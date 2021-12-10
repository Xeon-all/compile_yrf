#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "translate.h"

void InitTrans(){
	T_idx = 0;
	t_idx = 0;
	p_idx = 0;
	l_idx = 0;
  cn_func = 0;
}

int ToEeyore(struct TreeNode* node, struct Env* env, FILE* f, char* arg_prefix){
  char* prefix;
	struct TreeNode* CurrentNode;
	struct Symbol* CurrentSym;
  struct Env* CurrentEnv;

	prefix = (char*)malloc(sizeof(char)*(strlen(arg_prefix)+10));
	strcpy_s(prefix, strlen(arg_prefix) + 1, arg_prefix);
	strcat_s(prefix, 2, "\t");

  switch (node->type){
    case TN_ROOT:{//printf("handling root\n");
      CurrentNode = node->child[0];
      CurrentEnv = env;
      CurrentSym = env->head;
      
      while(CurrentSym){
        fprintf(f, "var ");
        if(CurrentSym->size != 0){
          fprintf(f, "%d ", CurrentSym->size);
        }
        fprintf(f, "T%d\n", CurrentSym->E_idx);
        CurrentSym = CurrentSym->suc;
      }
      for(int i = 0; i < env->n_t; ++ i)
        fprintf(f, "var t%d\n", i);
      CurrentEnv = CurrentEnv->child;//至少有一个main的环境
      while(CurrentNode){
        if(CurrentNode->type == TN_VDECL || CurrentNode->type == TN_CDECL){
          ToEeyore(CurrentNode, env, f, "");
        }
        else if(CurrentNode->type == TN_FUNCDEF_INT || CurrentNode->type == TN_FUNCDEF_VOID){
          t_idx = env->n_t;
          struct Env* tempEnv;
          tempEnv = env->child;
          for(int i = 0; i < cn_func; ++i, tempEnv = tempEnv->suc)
            t_idx += tempEnv->n_t;
          ToEeyore(CurrentNode, CurrentEnv, f, "");
          cn_func++;
          tempEnv = env->child;
          for(int i = 0; i < cn_func; ++i, tempEnv = tempEnv->suc)
            t_idx -= tempEnv->n_t;
          CurrentEnv = CurrentEnv->suc;
        }
        CurrentNode = CurrentNode->suc;
      }

      free(prefix);
      return -1;
    }
    case TN_VDECL:
    case TN_CDECL:{//处理初值的分配,声明已经完成
      // printf("handling decl\n");
      CurrentNode = node->child[0];
      while (CurrentNode){
        if(CurrentNode->child[1]){//需要赋初值,child1是exp(initval )
          int type = CurrentNode->child[1]->type;
          CurrentSym = FindSym(CurrentNode->child[0]->name, env, CurrentNode->child[0]->lineno);
          int size;
          size = CurrentSym->size / 4;
          switch (type){
            case TN_CINITVAL:
            case TN_INITVAL:{
              int dimension = 0;
              CurrentNode = CurrentNode->child[0];//clval
              
              dimension = CurrentSym->dimension;
              int* D_size = (int*)malloc(sizeof(int)*(dimension));
              CurrentNode = CurrentNode->child[0];
              for(int i = 0; CurrentNode; ++i, CurrentNode = CurrentNode->suc){//printf("i = %d\n", i);
                D_size[i] = CountConstExp(CurrentNode, env);
                CurrentSym->D_size[i] = D_size[i];
                // printf("exp(%d) val = %d\n", CurrentNode->idx, CountConstExp(CurrentNode, env));
                if(CurrentNode->suc == NULL){
                  CurrentNode = CurrentNode->parent->parent;//node = DEF
                  break;
                }
              }
              CurrentNode = CurrentNode->child[1];//node = Initval
              int idx = CurrentSym->E_idx;

              int i = 0;//iterator
              int start = 0, end = size, depth = -1;
              while(CurrentNode){//printf("handling node %d\n", CurrentNode->idx);
                int flag = 0; 
                switch (CurrentNode->type){
                  case TN_CINITVAL:
                  case TN_INITVAL:{
                    depth++;//确认在哪个块内
                    //define start 并补全,根据i depth 对齐
                    int align = 1;
                    for(int i = depth; i < dimension; ++i)
                      align *= D_size[i];
                    while(i < start) start += align;
                    for(; i < start; ++i)
                      fprintf(f, "%sT%d[%d] = 0\n", arg_prefix, idx, i * 4);
                    //define end
                    end = start + align;
                    if(CurrentNode->child[0] == NULL){
                      for(i = start; i < end; ++i)
                        fprintf(f, "%sT%d[%d] = 0\n", arg_prefix, idx, i * 4);
                    }
                    else{
                      CurrentNode = CurrentNode->child[0];
                      flag = 1;
                    }
                    break;
                  }
                  default:{//printf("a single %d\n", CurrentNode->value);
                    int temp_idx = ToEeyore(CurrentNode, env, f, arg_prefix);
                    if(temp_idx == -1)
                      fprintf(f, "%sT%d[%d] = %d\n", arg_prefix, idx, i * 4, CurrentNode->value);
                    else if(temp_idx == -2){
                      CurrentSym = FindSym(CurrentNode->name, env, CurrentNode->lineno);
                      fprintf(f, "%sT%d[%d] = T%d\n", arg_prefix, idx, i * 4, CurrentSym->E_idx);
                    }
                    else
                      fprintf(f, "%sT%d[%d] = t%d\n", arg_prefix, idx, i * 4, temp_idx);
                    ++i;
                  }
                }
                if(flag) continue;
                if(CurrentNode->suc) CurrentNode = CurrentNode->suc;
                else{//完成一个块,返回上一个
                  for(; i < end; ++i)
                    fprintf(f, "%sT%d[%d] = 0\n", arg_prefix, idx, i * 4);
                  //修改end
                  if(depth > 0){
                    depth--;
                    int align = 1;
                    for(int i = depth; i < dimension; ++i)
                      align *= D_size[i];
                    end = (end / align + 1) * align;
                    CurrentNode = CurrentNode->parent->suc;
                  }
                  else break;
                }
              }
              break;
            }
            default:{//初始化非数组
              int val = CountConstExp(CurrentNode->child[1], env);
              if(CurrentNode->type == TN_CDEF) CurrentSym->val[0] = val;
              int idx = ToEeyore(CurrentNode->child[1], env, f, arg_prefix);
              fprintf(f, "%sT%d = ", arg_prefix, CurrentSym->E_idx);
              if(idx == -1) fprintf(f, "%d\n", CurrentNode->child[1]->value);
              else if(idx == -2){
                CurrentSym = FindSym(CurrentNode->child[1]->name, env, CurrentNode->child[1]->lineno);
                fprintf(f, "T%d ", CurrentSym->E_idx);
              }
              else fprintf(f, "t%d\n", idx);
              break;
            }
          }
          
        }
        CurrentNode = CurrentNode->suc;
      }
      
      free(prefix);
      return -1;
    }
    case TN_UEXP:{//处理函数调用
      // printf("handling Uexp %d\n", node->idx);
      if(node->name){//是调用
        for(CurrentSym = funclisthead; CurrentSym && strcmp(node->name, CurrentSym->name) != 0; CurrentSym = CurrentSym->suc){}
        if(CurrentSym == NULL){
          fprintf(stderr, "ERROR: using a undecleared func at L%d", node->lineno);
          exit(0);
        }
        CurrentEnv = CurrentSym->funcEnv;
        CurrentNode = node;
        struct TreeNode* RSymNode = CurrentNode->child[1];
        struct Symbol* FSym;
        if(RSymNode == NULL){
          fprintf(stderr, "ERROR: fake rfuncp at L(%d)\n", CurrentNode->lineno);
          exit(0);
        }
        for(FSym = CurrentEnv->P_head;; FSym = FSym->suc, RSymNode = RSymNode->suc){
          int idx = ToEeyore(RSymNode, env, f, arg_prefix);
          if(idx == -1)
            fprintf(f, "%sparam %d\n", arg_prefix, RSymNode->value);
          else if(idx == -2){
            struct Symbol* tempSym;
            tempSym = FindSym(RSymNode->name, env, RSymNode->lineno);
            fprintf(f, "%sparam %s%d\n", arg_prefix, tempSym->EType, tempSym->E_idx);
          }else
            fprintf(f, "%sparam t%d\n", arg_prefix, idx);
          if(FSym->suc == NULL || RSymNode->suc == NULL)
            break;//printf("func %s called at L%d\n", CurrentSym->name, node->lineno);
        }
        if(CurrentNode->parent->type == TN_BLOCK){
          fprintf(f, "%scall f_%s\n", arg_prefix, CurrentSym->name);//stmt-exp形式的单独调用
          return -1;
        }
        //exp中的调用
        fprintf(f, "%st%d = call f_%s\n", arg_prefix, t_idx, CurrentSym->name);
        return t_idx++;
      }else{//是算式
        int idx = ToEeyore(node->child[1], env, f, arg_prefix);
        if(idx == -1){
          free(prefix);
          return -1;
        }
        fprintf(f, "%st%d = ", arg_prefix, t_idx);
        if(strcmp(node->child[0]->name, "-") == 0)
          fprintf(f, "- " );
        if(strcmp(node->child[0]->name, "!") == 0)
          fprintf(f, "! "); 
        if(idx == -2){
          CurrentSym = FindSym(node->child[1]->name, env, node->child[1]->lineno);
          fprintf(f, "T%d\n", CurrentSym->E_idx);
        }
        CurrentNode = node->child[0];//node type uop
        while (CurrentNode){
          fprintf(f, "%st%d = %s t%d\n", arg_prefix, ++t_idx, CurrentNode->name, --t_idx);
          t_idx++;
          CurrentNode = CurrentNode->pre;
        }
        free(prefix);
        return t_idx;
      }
      free(prefix);
      return -1;
    }
    case TN_LAEXP:{
      struct TreeNode* exp1 = node->child[0];
      struct TreeNode* exp2 = node->child[1];
      int flag_idx = t_idx;
      int f_l = l_idx;
      t_idx++;l_idx++;
      fprintf(f, "%st%d = 0\n", arg_prefix, flag_idx);
      int idx = ToEeyore(exp1, env, f, arg_prefix);
      fprintf(f, "%sif ", arg_prefix);
      if(idx == -1)
        fprintf(f, "%d", exp1->value);
      else if(idx == -2){
        CurrentSym = FindSym(exp1->name, env, exp1->lineno);
        fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d", idx);
      fprintf(f, " == 0 goto l%d\n", f_l);
      idx = ToEeyore(exp2, env, f, arg_prefix);
      fprintf(f, "%sif ", arg_prefix);
      if(idx == -1)
        fprintf(f, "%d", exp2->value);
      else if(idx == -2){
        CurrentSym = FindSym(exp2->name, env, exp2->lineno);
        fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d", idx);
      fprintf(f, " == 0 goto l%d\n", f_l);
      fprintf(f, "%st%d = 1\n", arg_prefix, flag_idx);
      fprintf(f, "l%d:\n", f_l);

      free(prefix);
      return flag_idx;
    }
    case TN_LOEXP:{
      struct TreeNode* exp1 = node->child[0];
      struct TreeNode* exp2 = node->child[1];
      int flag_idx = t_idx;
      int t_l = l_idx;
      t_idx++;l_idx++;
      fprintf(f, "%st%d = 1\n", arg_prefix, flag_idx);
      int idx;
      idx = ToEeyore(exp1, env, f, arg_prefix);
      fprintf(f, "%sif ", arg_prefix);
      if(idx == -1)
        fprintf(f, "%d", exp1->value);
      else if(idx == -2){
        CurrentSym = FindSym(exp1->name, env, exp1->lineno);
        fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d", idx);
      fprintf(f, " == 1 goto l%d\n", t_l);
      idx = ToEeyore(exp2, env, f, arg_prefix);
      fprintf(f, "%sif ", arg_prefix);
      if(idx == -1)
        fprintf(f, "%d", exp2->value);
      else if(idx == -2){
        CurrentSym = FindSym(exp2->name, env, exp2->lineno);
        fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d", idx);
      fprintf(f, " == 1 goto l%d\n", t_l);
      fprintf(f, "%st%d = 0\n", arg_prefix, flag_idx);
      fprintf(f, "l%d:\n", t_l);

      free(prefix);
      return flag_idx;
    }
    case TN_AEXP:
    case TN_MEXP:
    case TN_REXP:
    case TN_EEXP:{//一定有两个child
      // printf("handling exp\n");
      CurrentNode = node;//printf("t_idx of exp: %d\n", t_idx);

      if(CurrentNode->child[0] == NULL || CurrentNode->child[1] == NULL){
        fprintf(stderr, ">> ERROR: wrong exp at L%d\n", CurrentNode->lineno);
        exit(-3);
      }

      int var1 = ToEeyore(CurrentNode->child[0], env, f, arg_prefix);
      int var2 = ToEeyore(CurrentNode->child[1], env, f, arg_prefix);
      // printf("test var1 = %d var2 = %d", var1, var2);
      fprintf(f, "%st%d = ", arg_prefix, t_idx);
      // printf("%st%d = ", arg_prefix, t_idx);
      if(var1 == -1) fprintf(f, "%d ", CurrentNode->child[0]->value);
      else if(var1 == -2){//printf("lval in exp\n");
        CurrentSym = FindSym(CurrentNode->child[0]->name, env, CurrentNode->child[0]->lineno);
        fprintf(f, "%s%d ", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d ", var1);
      fprintf(f, "%s ", CurrentNode->name);
      if(var2 == -1) fprintf(f, "%d\n", CurrentNode->child[1]->value);
      else if(var2 == -2){
        CurrentSym = FindSym(CurrentNode->child[1]->name, env, CurrentNode->child[1]->lineno);
        // if(CurrentSym == NULL) printf("find sym fail\n");
        // else printf("find sym %s", CurrentSym->name);
        fprintf(f, "%s%d\n", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d\n", var2);
      //printf("test\n");
      free(prefix);
      return t_idx++;
    }
    case TN_FUNCDEF_INT:
    case TN_FUNCDEF_VOID:{//printf("handling func %s\n", node->name);
      int p_n = 0;
      struct Symbol* tempSym;
      tempSym = env->P_head;
      while(tempSym){
        ++p_n;
        tempSym = tempSym->suc;
      }
      fprintf(f, "\n%sf_%s [%d]\n", arg_prefix, node->name, p_n);

      //在这里完成所有函数中临时/原生变量的声明
      CurrentSym = env->head;
      while (CurrentSym){
        fprintf(f, "%svar %s%d\n", prefix, CurrentSym->EType, CurrentSym->E_idx);
        CurrentSym = CurrentSym->suc;
      }
      int sumn_t = EnvDeclare(env, f, prefix);//返回临时变量的数量
      t_idx -= sumn_t;
      ToEeyore(node->child[0], env, f, prefix);//block的转化, env是当前函数环境

      fprintf(f, "%sreturn", prefix);
      if(node->type == TN_FUNCDEF_INT) fprintf(f, " 0");
      fprintf(f, "\nend f_%s\n", node->name);
      free(prefix);
      return -1;
    }
    case TN_BLOCK:{//printf("handling block at L%d\n", node->lineno);
      CurrentNode = node->child[0];
      CurrentEnv = env->child;
      while (CurrentNode){
        switch (CurrentNode->type){
          case TN_BLOCK:
            ToEeyore(CurrentNode, CurrentEnv, f, prefix);
            CurrentEnv = CurrentEnv->suc;
            break;
          case TN_STMT_WHILE:{
            if(CurrentNode->child[1]->type == TN_BLOCK){
              ToEeyore(CurrentNode, CurrentEnv, f, arg_prefix);
              CurrentEnv = CurrentEnv->suc;
            }
            else
              ToEeyore(CurrentNode, env, f, arg_prefix);
            break;
          }
          case TN_STMT_IF:{
            if(CurrentNode->child[1]->type == TN_BLOCK){
              ToEeyore(CurrentNode, CurrentEnv, f, arg_prefix);
              CurrentEnv = CurrentEnv->suc;
            }else{
              if(CurrentNode->child[2]){
                if(CurrentNode->child[1]->type == TN_BLOCK){
                  ToEeyore(CurrentNode, CurrentEnv, f, arg_prefix);
                  CurrentEnv = CurrentEnv->suc;
                }
                else
                  ToEeyore(CurrentNode, env, f, arg_prefix);
              }
              else
                ToEeyore(CurrentNode, env, f, arg_prefix);
            }
            break;
          }
          default:
            ToEeyore(CurrentNode, env, f, arg_prefix);
            break;
        }
        CurrentNode = CurrentNode->suc;
      }
      free(prefix);
      return -1;
    }
    case TN_STMT_RETURN:{//printf("handling return at L%d\n", node->lineno);
      if(node->child[0]){
        int idx;//printf("child type%d\n", node->child[0]->type);
        idx = ToEeyore(node->child[0], env, f, arg_prefix);
        if(node->child[0]->name)
          CurrentSym = FindSym(node->child[0]->name, env, node->child[0]->lineno);
        fprintf(f, "%sreturn", arg_prefix);
        if(idx == -1)
          fprintf(f, " %d", node->child[0]->value);
        else if(idx == -2)
          fprintf(f, " %s%d", CurrentSym->EType, CurrentSym->E_idx);
        else{
          fprintf(f, " t%d", idx);
          if(node->child[0]->name)
            fprintf(f, "[0]");
        }
        // printf("in return %d\n", idx);
      }
      fprintf(f, "\n");
      free(prefix);
      return -1;
    }
    case TN_STMT_ASSIGN:{
      CurrentNode = node;
      int idx1 = ToEeyore(CurrentNode->child[0], env, f, arg_prefix);
      int idx2 = ToEeyore(CurrentNode->child[1], env, f, arg_prefix);
      CurrentSym = FindSym(CurrentNode->child[0]->name, env, CurrentNode->child[0]->lineno);
      if(idx1 == -2)
        fprintf(f, "%s%s%d = ", arg_prefix, CurrentSym->EType, CurrentSym->E_idx);
      else{
        fprintf(f, "%st%d[0] = ", arg_prefix, idx1);
      }
      if(idx2 == -1) fprintf(f, "%d\n", CurrentNode->child[1]->value);
      else if(idx2 == -2){
        CurrentSym = FindSym(CurrentNode->child[1]->name, env, CurrentNode->child[1]->lineno);
        fprintf(f, "%s%d\n", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d\n", idx2);
      free(prefix);
      return -1;
    }
    case TN_STMT_IF:{
      int f_l, e_l;
      f_l = l_idx;
      struct TreeNode* Cond = node->child[0];
      struct TreeNode* if_block = node->child[1];
      struct TreeNode* else_block = node->child[2];
      struct Env* if_env;
      struct Env* else_env;
      struct Env* cond_env;
      if(else_block){//if-else
        e_l = l_idx + 1;
        l_idx += 2;

        if(if_block->type == TN_BLOCK){
          if_env = env;
          cond_env = env->parent;
          if(else_block->type == TN_BLOCK)
            else_env = env->suc;
          else
            else_env = env->parent;
        }
        else{
          if(else_block->type == TN_BLOCK){
            else_env = env;
            if_env = env->parent;
            cond_env = env->parent;
          }
          else{
            else_env = env;
            if_env = env;
            cond_env = env;
          }
        }
          
        int idx;
        idx = ToEeyore(Cond, env, f, arg_prefix);
        fprintf(f, "%sif ", arg_prefix);
        if(idx == -1)
          fprintf(f, "%d", Cond->value);
        else if(idx == -2){
          CurrentSym = FindSym(Cond->name, cond_env, Cond->lineno);
          fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
        }
        else fprintf(f, "t%d", idx);
        fprintf(f, " == 0 goto l%d\n", f_l);
        ToEeyore(if_block, if_env, f, prefix);
        fprintf(f, "%sgoto l%d\n", arg_prefix, e_l);
        fprintf(f, "l%d:\n", f_l);
        ToEeyore(else_block, else_env, f, arg_prefix);
        fprintf(f, "l%d:\n", e_l);
      }else{//only if
        l_idx++;
        if_env = env;
        if(if_block->type == TN_BLOCK)
          cond_env = env->parent;
        else
          cond_env = env;
          
        int idx;
        idx = ToEeyore(Cond, env, f, arg_prefix);
        fprintf(f, "%sif ", arg_prefix);
        if(idx == -1)
          fprintf(f, "%d", Cond->value);
        else if(idx == -2){
          CurrentSym = FindSym(Cond->name, cond_env, Cond->lineno);
          fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
        }
        else fprintf(f, "t%d", idx);
        fprintf(f, " == 0 goto l%d\n", f_l);
        ToEeyore(if_block, if_env, f, prefix);
        fprintf(f, "l%d:\n", f_l);
      }
      free(prefix);
      return -1;
    }
    case TN_STMT_WHILE:{
      int s_l, e_l;
      s_l = l_idx;
      e_l = l_idx + 1;
      l_idx += 2;
      struct Env* cond_env;
      struct Env* block_env;
      struct TreeNode* Cond;
      struct TreeNode* Block;
      Cond = node->child[0];
      Block = node->child[1];
      block_env = env;
      if(Block->type == TN_BLOCK)
        cond_env = env->parent;
      else
        cond_env = env;

      fprintf(f, "l%d:\n", s_l);
      int idx = ToEeyore(Cond, cond_env, f, arg_prefix);
      fprintf(f, "%sif ", arg_prefix);
      if(idx == -1)
        fprintf(f, "%d", Cond->value);
      else if(idx == -2){
        CurrentSym = FindSym(Cond->name, cond_env, Cond->lineno);
        fprintf(f, "%s%d", CurrentSym->EType, CurrentSym->E_idx);
      }
      else fprintf(f, "t%d", idx);
      fprintf(f, " == 0 goto l%d\n", e_l);
      ToEeyore(Block, block_env, f, arg_prefix);
      fprintf(f, "%sgoto l%d\n", arg_prefix, s_l);
      fprintf(f, "l%d:\n", e_l);

      free(prefix);
      return -1;
    }
    case TN_STMT_CONTINUE:
    case TN_STMT_BREAK:{
      fprintf(f, "%sgoto l%d\n", arg_prefix, node->value);
      free(prefix);
      return -1;
    }
    case TN_NUMBER:{//printf("handling number %d\n", node->value);
      free(prefix);
      return -1;
    }
    case TN_CLVAL:
    case TN_LVAL:{//printf("handling lval %s\n", node->name);
      CurrentSym = FindSym(node->name, env, node->lineno);
      if(node->child[0] == NULL){
        free(prefix);
        return -2;
      }
      //返回地址位置,如果取数字别处处理
      // int d = strcmp(CurrentSym->EType, "p") == 0 ? 1 : 0;
      int idx1, idx2, d = 1;
      CurrentNode = node->child[0];//node type exp(suffix)

      idx1 = ToEeyore(CurrentNode, env, f, arg_prefix);
      int val;
      if(idx1 == -1) val = CurrentNode->value;
      struct Symbol* tempSym;
      if(idx1 == -2) tempSym = FindSym(CurrentNode->name, env, CurrentNode->lineno);
      CurrentNode = CurrentNode->suc;
      while (CurrentNode){//各个计算式子
        idx2 = ToEeyore(CurrentNode, env, f, arg_prefix);
        fprintf(f, "%st%d = t%d * %d\n", arg_prefix, t_idx++, idx1, CurrentSym->D_size[d++]);
        idx1 = t_idx - 1;
        fprintf(f, "%st%d = t%d + t%d\n", arg_prefix, t_idx++, idx1, idx2);
        idx1 = t_idx - 1;
      }

      fprintf(f, "%st%d = 4 * ", arg_prefix, t_idx++);
      if(idx1 == -1)
        fprintf(f, "%d\n", val);
      else if(idx1 == -2)
        fprintf(f, "%s%d\n", tempSym->EType, tempSym->E_idx);
      else
        fprintf(f, "t%d\n", idx1);
      fprintf(f, "%st%d = %s%d + t%d\n", arg_prefix, t_idx, CurrentSym->EType, CurrentSym->E_idx, t_idx - 1);
      if(node->parent->type != TN_STMT_ASSIGN || node != node->parent->child[0]){
        t_idx++;
        fprintf(f, "%st%d = t%d[0]\n", arg_prefix, t_idx, t_idx - 1);
      }
      return t_idx++;
    }
    default:fprintf(stderr, ">> ERROR: translating Unknown parse tree node(%d) at L%d\n", node->idx, node->lineno);exit(-3);
  }
}

int EnvDeclare(struct Env* env, FILE* f, char* prefix){
  // printf("env%d n_t %d t_idx %d\n", env->idx, env->n_t, t_idx);
  int sumn_t = 0;
  if(env->n_t){ 
    for(int i = t_idx; i < t_idx + env->n_t; ++i)
      fprintf(f, "%svar t%d\n", prefix, i);
    t_idx += env->n_t;
    sumn_t += env->n_t;
  }
  // if(env->child){
  //   struct Env* CurrentEnv;
  //   CurrentEnv = env->child;
  //   sumn_t += EnvDeclare(CurrentEnv, f, prefix);
  //   while (CurrentEnv->suc){
  //     CurrentEnv = CurrentEnv->suc;
  //     sumn_t += EnvDeclare(CurrentEnv, f, prefix);
  //   }
  // }
  return sumn_t;
}

