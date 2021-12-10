#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

struct TreeNode* new_node(int arg_type, int arg_lineno, char* arg_name){
  struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  node->type = arg_type;
  node->lineno = arg_lineno;
  node->idx = n_treenode++;
  node->name = arg_name;
  node->value = -1;
  node->parent = NULL;
  node->pre = NULL;
  node->suc = NULL;
  switch (node->type){
  case TN_CDECL: node->childNum = CN_CDECL;break;
  case TN_CDEF: node->childNum = CN_CDEF;break;
  case TN_ROOT: node->childNum = CN_ROOT;break;
  case TN_VOID: node->childNum = CN_VOID;break;
  case TN_CLVAL: node->childNum = CN_CLVAL;break;
  case TN_CINITVAL: node->childNum = CN_CINITVAL;break;
  case TN_NUMBER: node->childNum = CN_NUMBER;break;
  // case TN_PEXP: node->childNum = CN_PEXP;break;
  case TN_UEXP: node->childNum = CN_UEXP;break;
  case TN_AEXP: node->childNum = CN_AEXP;break;
  case TN_MEXP: node->childNum = CN_MEXP;break;
  // case TN_CEXP: node->childNum = CN_CEXP;break;
  case TN_VDECL: node->childNum = CN_VDECL;break;
  case TN_VDEF: node->childNum = CN_VDEF;break;
  case TN_INITVAL: node->childNum = CN_INITVAL;break;
  case TN_FUNCDEF_INT: node->childNum = CN_FUNCDEF_INT;break;
  case TN_FUNCDEF_VOID: node->childNum = CN_FUNCDEF_VOID;break;
  case TN_STMT_RETURN: node->childNum = CN_STMT_RETURN;break;
  case TN_BLOCK: node->childNum = CN_BLOCK;break;
  case TN_LVAL: node->childNum = CN_LVAL;break;
  case TN_STMT_ASSIGN: node->childNum = CN_STMT_ASSIGN;break;
  case TN_FUNCFP: node->childNum = CN_FUNCFP;break;
  case TN_UOP: node->childNum = CN_UOP;break;
  case TN_STMT_IF: node->childNum = CN_STMT_IF;break;
  case TN_STMT_WHILE: node->childNum = CN_STMT_WHILE;break;
  case TN_STMT_BREAK: node->childNum = CN_STMT_BREAK;break;
  case TN_STMT_CONTINUE: node->childNum = CN_STMT_CONTINUE;break;
  case TN_REXP: node->childNum = CN_REXP;break;
  case TN_EEXP: node->childNum = CN_EEXP;break;
  case TN_LAEXP: node->childNum = CN_LAEXP;break;
  case TN_LOEXP: node->childNum = CN_LOEXP;break;
    
  default: printf("unrecognized tree node");exit(-1);break;
  }
  for (int i = 0; i < node->childNum; i++)
		node->child[i] = NULL;
  return node;
}

void PrintTreeNode(struct TreeNode* arg_node, char* arg_prefix, FILE* f){
	char* prefix;
	if (arg_prefix == NULL)
		prefix = _strdup("");
	else
		prefix = _strdup(arg_prefix);
	switch(arg_node->type){
	case TN_CDECL: fprintf(f, "%s[*]ConstDecl(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
	case TN_CDEF: fprintf(f, "%s[*]ConstDef(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_ROOT: fprintf(f, "%s[*]ROOT(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
	case TN_VOID: fprintf(f, "%s[*]void(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
	case TN_CLVAL: fprintf(f, "%s[*]ConstLVal(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
	case TN_CINITVAL: fprintf(f, "%s[*]ConstInitVal(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_NUMBER: fprintf(f, "%s[*]Number(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  // case TN_PEXP: fprintf(f, "%s[*]PrimaryExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_UEXP: fprintf(f, "%s[*]UnaryExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_AEXP: fprintf(f, "%s[*]AddExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_MEXP: fprintf(f, "%s[*]MulExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  // case TN_CEXP: fprintf(f, "%s[*]ConstExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_VDECL: fprintf(f, "%s[*]VarDecl(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_VDEF: fprintf(f, "%s[*]VarDef(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_INITVAL: fprintf(f, "%s[*]InitVal(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_FUNCDEF_INT: fprintf(f, "%s[*]FuncDefInt(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_FUNCDEF_VOID: fprintf(f, "%s[*]FuncDefVoid(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_STMT_RETURN: fprintf(f, "%s[*]Return(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_BLOCK: fprintf(f, "%s[*]Block(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_LVAL: fprintf(f, "%s[*]LVal(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_STMT_ASSIGN: fprintf(f, "%s[*]Assign(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_FUNCFP: fprintf(f, "%s[*]FuncFP(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_UOP: fprintf(f, "%s[*]UnaryOP(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_STMT_IF: fprintf(f, "%s[*]IF(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_STMT_WHILE: fprintf(f, "%s[*]While(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_STMT_BREAK: fprintf(f, "%s[*]Break(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_STMT_CONTINUE: fprintf(f, "%s[*]Continue(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_REXP: fprintf(f, "%s[*]RelExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_EEXP: fprintf(f, "%s[*]EpExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_LAEXP: fprintf(f, "%s[*]LAndExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
  case TN_LOEXP: fprintf(f, "%s[*]LOrExp(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
	default: fprintf(f, "%s[!]UNKNOWN(%d) at L%d", prefix, arg_node->idx, arg_node->lineno); break;
	}
	if (arg_node->parent == NULL)
		fprintf(f, ", P (N)");
	else
		fprintf(f, ", P (%d)", arg_node->parent->idx);
	if (arg_node->pre == NULL)
		fprintf(f, " L (N)");
	else
		fprintf(f, " L (%d)", arg_node->pre->idx);
	if (arg_node->suc == NULL)
		fprintf(f, " R (N)");
	else
		fprintf(f, " R (%d)", arg_node->suc->idx);
  if(arg_node->value != -1)
    fprintf(f, "value = %d", arg_node->value);
  if(arg_node->name != NULL)
    fprintf(f, "name = %s", arg_node->name);
  fprintf(f, "\n");
}

void PrintTree(struct TreeNode *arg_node, int depth, FILE* f){
	char* prefix;
	char prefix_unit[6] = "    ";
	struct TreeNode *tmp_node;
	if (arg_node == NULL){
    fprintf(f, "print NULL node\n");
    return;
  }
	if (depth == 0){
		PrintTreeNode(arg_node, NULL, f);
		prefix = (char*)malloc(sizeof(char)*4);
		prefix[0] = '\0';
	}
	else{
		prefix = (char*)malloc(sizeof(char)*depth*4+10);
		memset(prefix, 0, sizeof(char)*depth*4+10);
		for (int i = 0; i < depth; i++)
			strcat_s(prefix, strlen(prefix_unit) + 1, prefix_unit);
		PrintTreeNode(arg_node, prefix, f);
	}

	for (int i = 0; i < arg_node->childNum; i++){
		//fprintf(f, "%s  child(s) %d of (%d)\n", prefix, i+1, arg_node->idx);
		tmp_node = arg_node->child[i];
		if (tmp_node == NULL)
		{
			fprintf(f, "%s    NONE\n", prefix);
			continue;
		}
		while (tmp_node != NULL)
		{
			PrintTree(tmp_node, depth+1, f);
			tmp_node = tmp_node->suc;
		}
	}

	free(prefix);
}

struct Env* new_env(int lineno){
  struct Env* node = (struct Env*)malloc(sizeof(struct Env));
  node->lineno = lineno;
  node->child = NULL;
  node->parent = NULL;
  node->suc = NULL;
  node->head = NULL;
  node->P_head = NULL;
  node->idx = n_env++;
  node->n_t = 0;
  // printf("creatint env %d at L %d\n", node->idx, lineno);
  return node;
}

void PrintEnvNode(struct Env* arg_node, char* arg_prefix, FILE* f){
  char* prefix;
	if (arg_prefix == NULL)
		prefix = _strdup("");
	else
		prefix = _strdup(arg_prefix);
  if (arg_node->parent == NULL)
		fprintf(f, "%sENV P (N)", prefix);
	else
		fprintf(f, "%sENV P (%d)", prefix, arg_node->parent->idx);
  fprintf(f, " idx(%d) n_t:%d", arg_node->idx, arg_node->n_t);
	if(arg_node->head == NULL)
    fprintf(f, ", NO SYMBOL \n");
  else {
    fprintf(f, "\n");
    PrintSymtab(arg_node->head, arg_prefix, f);
  }
  if(arg_node->P_head){
    fprintf(f, "\n");
    PrintSymtab(arg_node->P_head, arg_prefix, f);
  }
}

void PrintEnv(struct Env* arg_node, int depth, FILE* f){
  char* prefix;
	char prefix_unit[6] = "    ";
	struct Env *tmp_node;
	if (arg_node == NULL){
    fprintf(f, "print NULL node\n");
    return;
  }
	if (depth == 0){
		PrintEnvNode(arg_node, NULL, f);
		prefix = (char*)malloc(sizeof(char)*4);
		prefix[0] = '\0';
	}
	else{
		prefix = (char*)malloc(sizeof(char)*depth*4+10);
		memset(prefix, 0, sizeof(char)*depth*4+10);
		for (int i = 0; i < depth; i++)
			strcat_s(prefix, strlen(prefix_unit) + 1, prefix_unit);
		PrintEnvNode(arg_node, prefix, f);
	}
  if(arg_node->child)
    PrintEnv(arg_node->child, depth + 1, f);
  tmp_node = arg_node->suc;
  while (tmp_node){
    PrintEnv(tmp_node, depth, f);
    tmp_node = tmp_node->suc;
  }
	free(prefix);
}

void SetEnv(struct TreeNode* block, struct Env* env){
  struct Env* CurrentEnvChild;
  struct Symbol* sym;
  struct TreeNode* CurrentNode;
  if(block->type != TN_ROOT)
    Count_n_t(env, block);
  CurrentNode = block->child[0];
  while(CurrentNode){
    switch (CurrentNode->type){
      case TN_VDECL:
      case TN_CDECL:{
          CurrentNode = CurrentNode->child[0];//进入def节点,至少有一个
          if(env->head == NULL){
            if(CurrentNode->type == TN_CDEF)
              env->head = new_symbol(CurrentNode->lineno, CurrentNode->name, "T", "c");
            else env->head = new_symbol(CurrentNode->lineno, CurrentNode->name, "T", "v");
            env->head->E_idx = T_idx++;
            Count_n_t(env, CurrentNode->child[0]);//计算LVAL定义时数组的若干表达式,可以传入NULL;传入constsuffix
            SetArrSize(CurrentNode->child[0], env->head, env);
            Count_n_t(env, CurrentNode->child[1]);
            if(CurrentNode->type == TN_CDEF)
              SetSymVal(env->head, CurrentNode->child[1], env);
            if(CurrentNode->suc)
              CurrentNode = CurrentNode->suc;
            else {
              CurrentNode = CurrentNode->parent;
              break;
            }
          }
          sym = env->head;
          while (sym->suc){
            sym = sym->suc;
          }
          while (CurrentNode){//node type = def
            Count_n_t(env, CurrentNode->child[0]);
            Count_n_t(env, CurrentNode->child[1]);
            if(CurrentNode->type == TN_CDEF)
              sym->suc = new_symbol(CurrentNode->lineno, CurrentNode->name, "T", "c");
            else sym->suc = new_symbol(CurrentNode->lineno, CurrentNode->name, "T", "v");
            sym = sym->suc;
            SetArrSize(CurrentNode->child[0], sym, env);
            if(CurrentNode->type == TN_CDEF)
              SetSymVal(sym, CurrentNode->child[1], env);
            sym->E_idx = T_idx++;
            if(CurrentNode->suc){
              CurrentNode = CurrentNode->suc;
            }
            else break;
          }
          CurrentNode = CurrentNode->parent;
          break;
        }
      case TN_FUNCDEF_INT://只在root的子节点中
      case TN_FUNCDEF_VOID:{//要处理参数数组
          struct Env* NewEnv;
          struct Symbol* NewSym;
          NewEnv = new_env(CurrentNode->lineno);
          NewEnv->parent = env;
          if(env->child == NULL){
            env->child = NewEnv;
            CurrentEnvChild = NewEnv;
          }
          else{
            CurrentEnvChild->suc = NewEnv;
            CurrentEnvChild = CurrentEnvChild->suc;
          }
          if(CurrentNode->child[1]){//函数有参数
            int idx = 0;
            CurrentNode = CurrentNode->child[1];
            NewEnv->P_head = new_symbol(CurrentNode->lineno, CurrentNode->name, "p", "v");
            NewEnv->P_head->E_idx = idx++;
            NewSym = NewEnv->P_head;
            SetArrSize(CurrentNode, NewSym, NewEnv);
            while (CurrentNode){
              if(CurrentNode->suc)
                CurrentNode = CurrentNode->suc;
              else break;
              NewSym->suc = new_symbol(CurrentNode->lineno, CurrentNode->name, "p", "v");
              NewSym = NewSym->suc;//printf("test node%d\n", CurrentNode->idx);
              SetArrSize(CurrentNode, NewSym, NewEnv);
              NewSym->E_idx = idx++;
            }
            CurrentNode = CurrentNode->parent;
          }
          NewSym = new_symbol(CurrentNode->lineno, CurrentNode->name, "f", "f");
          if(funclisthead == NULL) funclisthead = NewSym;
          else{
            sym = funclisthead;
            while (sym->suc){
              sym = sym->suc;
            }
            sym->suc = NewSym;
          }
          NewSym->funcEnv = NewEnv;
          SetEnv(CurrentNode->child[0], NewEnv);
          break;
        }
      case TN_BLOCK:{
          struct Env* NewEnv;
          NewEnv = new_env(CurrentNode->lineno);
          NewEnv->parent = env;
          if(env->child == NULL){
            env->child = NewEnv;
            CurrentEnvChild = NewEnv;
          }
          else{
            CurrentEnvChild->suc = NewEnv;
            CurrentEnvChild = CurrentEnvChild->suc;
          }
          SetEnv(CurrentNode, NewEnv);
          break;
        }
      case TN_STMT_IF:{
        // Count_n_t(env, CurrentNode->child[0]);
        if(CurrentNode->child[1]->type == TN_BLOCK){
          struct Env* NewEnv;
          NewEnv = new_env(CurrentNode->lineno);
          NewEnv->parent = env;
          if(env->child == NULL){
            env->child = NewEnv;
            CurrentEnvChild = NewEnv;
          }
          else{
            CurrentEnvChild->suc = NewEnv;
            CurrentEnvChild = CurrentEnvChild->suc;
          }
          SetEnv(CurrentNode->child[1], NewEnv);
          break;
        }
        // else  
        //   Count_n_t(env, CurrentNode->child[1]);
        if(CurrentNode->child[2]){
          if(CurrentNode->child[2]->type == TN_BLOCK){
            struct Env* NewEnv;
            NewEnv = new_env(CurrentNode->lineno);
            NewEnv->parent = env;
            if(env->child == NULL){
              env->child = NewEnv;
              CurrentEnvChild = NewEnv;
            }
            else{
              CurrentEnvChild->suc = NewEnv;
              CurrentEnvChild = CurrentEnvChild->suc;
            }
            SetEnv(CurrentNode->child[2], NewEnv);
            break;
          }
          // else 
          //   Count_n_t(env, CurrentNode->child[2]);
        }
      }
      case TN_STMT_WHILE:{
        if(CurrentNode->child[1]->type == TN_BLOCK){
          struct Env* NewEnv;
          NewEnv = new_env(CurrentNode->lineno);
          // Count_n_t(NewEnv, CurrentNode->child[0]);
          NewEnv->parent = env;
          if(env->child == NULL){
            env->child = NewEnv;
            CurrentEnvChild = NewEnv;
          }
          else{
            CurrentEnvChild->suc = NewEnv;
            CurrentEnvChild = CurrentEnvChild->suc;
          }
          SetEnv(CurrentNode->child[1], NewEnv);
          break;
        }
        // else
        //   Count_n_t(env, CurrentNode->child[1]);
        break;
      }
      case TN_REXP:
      case TN_EEXP:
      case TN_LAEXP:
      case TN_LOEXP:
      case TN_UEXP:
      case TN_AEXP:
      case TN_MEXP:{
        // Count_n_t(env, CurrentNode);
        break;
      }
      case TN_STMT_ASSIGN:{//printf("encounter assign\n");

        // Count_n_t(env, CurrentNode->child[0]);
        // Count_n_t(env, CurrentNode->child[1]);
        // if(CurrentNode->child[0]->child[0]) env->n_t--;//等号左边的数组调用需要减少额外一个临时变量
        // int type = CurrentNode->child[1]->type;
        // if(type == TN_AEXP || type == TN_MEXP || type == TN_UEXP) env->n_t--;//可以不借助临时变量一步到位

        break;
      }
      case TN_STMT_RETURN:{
        // if(CurrentNode->child[0])
        //   Count_n_t(env, CurrentNode->child[0]);
        break;
      }
      default:break;
    }
    CurrentNode = CurrentNode->suc;
  }
}

void InitEnv(){
  n_env = 0;
  RootEnv = new_env(-1);
  struct Symbol* sym;
  sym = new_symbol(-1, "getint", "f", "f");
  sym->funcEnv = new_env(-1);
  funclisthead = sym;
  sym->suc = new_symbol(-1, "getch", "f", "f");
  sym->funcEnv = new_env(-1);
  sym = sym->suc;
  sym->suc = new_symbol(-1, "getarray", "f", "f");
  sym->funcEnv = new_env(-1);
  sym->funcEnv->P_head = new_symbol(-1, NULL, NULL, NULL);
  sym = sym->suc;
  sym->suc = new_symbol(-1, "putint", "f", "f");
  sym->funcEnv = new_env(-1);
  sym->funcEnv->P_head = new_symbol(-1, NULL, NULL, NULL);
  sym = sym->suc;
  sym->suc = new_symbol(-1, "putch", "f", "f");
  sym->funcEnv = new_env(-1);
  sym->funcEnv->P_head = new_symbol(-1, NULL, NULL, NULL);
  sym = sym->suc;
  sym->suc = new_symbol(-1, "putarray", "f", "f");
  sym->funcEnv = new_env(-1);
  sym->funcEnv->P_head = new_symbol(-1, NULL, NULL, NULL);
  sym->funcEnv->P_head->suc = new_symbol(-1, NULL, NULL, NULL);
  sym = sym->suc;
}

struct Symbol* FindSym(char* name, struct Env* env, int lineno){
  // printf("finding sym (%s) in env(%d) at L%d\n", name, env->idx, lineno);
  struct Symbol* sym = env->head;
  while(sym){
    if(strcmp(sym->name, name) == 0 && sym->lineno <= lineno) return sym;
    sym = sym->suc;
  }
  sym = env->P_head;
  while(sym){
    if(strcmp(sym->name, name) == 0 && sym->lineno <= lineno) return sym;
    sym = sym->suc;
  }
  if(env->parent)
    FindSym(name, env->parent, lineno);
  else{
    fprintf(stderr, "ERROR: no such symbol\n");
    exit(-1);
  }
  exit(0);
}

void Count_n_t(struct Env* env, struct TreeNode* exp){
  // printf("counting n_t of env(%d) %d\n", env->idx, env->n_t++);
  if(exp == NULL) return;
  // else printf("exp exist type%d\n", exp->type);
  switch (exp->type){
    case TN_VDECL:
    case TN_CDECL:break;
    case TN_UEXP:{
      struct TreeNode* op = exp->child[0];
      struct TreeNode* NewExp = exp->child[1];
      if(exp->name) {
        env->n_t++;
        if(exp->parent->type == TN_BLOCK)
          env->n_t--;//单独调用不需要临时变量
      }
      if(op) env->n_t--;
      while (NewExp){//函数参数
        Count_n_t(env, NewExp);
        NewExp = NewExp->suc;
      }
      while (op){//printf("add uexp n_t at L%d\n", exp->lineno);
        env->n_t++;
        op = op->pre;
      }
      break;
    }
    case TN_LAEXP:
    case TN_LOEXP:
    case TN_AEXP:
    case TN_MEXP:
    case TN_REXP:
    case TN_EEXP:{
      if(exp->parent == NULL) fprintf(stderr, "ERROR: invalid exp(%d) count n_t called\n", exp->idx);
      env->n_t++;
      Count_n_t(env, exp->child[0]);
      Count_n_t(env, exp->child[1]);
      break;
    }
    case TN_CLVAL:{//处理数组定义,size会直接算出定值,不需要计算这个
      // if(exp->child[0]){
      //   exp = exp->child[0];
      //   while (exp && exp->suc){
      //     if(exp->type != TN_NUMBER)
      //       env->n_t++;
      //     Count_n_t(env, exp);
      //     exp = exp->suc;
      //   }
      // }
      break;
    }
    case TN_LVAL:{
      if(exp->child[0]){//处理数组调用
        // exp = exp->child[0];//printf("add arr n_t at L%d\n", exp->lineno);
        // while (exp && exp->suc){
        //   if(exp->type != TN_NUMBER)
        //     env->n_t++;
        //   Count_n_t(env, exp);
        //   env->n_t += 2;//统合偏移量需要的临时变量
        //   exp = exp->suc;
        // }
        // env->n_t++;
        // Count_n_t(env, exp);
        // env->n_t += 2;//意味着exp求值之后要再*4,然后给出偏移后的地址
        // switch (exp->parent->type){
        //   case TN_AEXP:
        //   case TN_MEXP:
        //   case TN_REXP:
        //   case TN_EEXP:
        //   case TN_LAEXP:
        //   case TN_LOEXP: env->n_t++;
        //   default: break;
        // }
        exp = exp->child[0];
        env->n_t += 3;
        Count_n_t(env, exp);
        while (exp->suc){
          env->n_t += 2;
          exp = exp->suc;
          Count_n_t(env, exp);
        }
      }
    }
    case TN_CINITVAL:
    case TN_INITVAL:{
      if(exp->child[0]){
        exp = exp->child[0];
        while (exp){
          Count_n_t(env, exp);
          exp = exp->suc;
        }
      }
      break;
    }
    case TN_NUMBER: break;
    case TN_BLOCK:{
      exp = exp->child[0];
      while (exp){
        Count_n_t(env, exp);
        exp = exp->suc;
      }
      break;
    }
    case TN_STMT_ASSIGN:{
      Count_n_t(env, exp->child[0]);
      Count_n_t(env, exp->child[1]);
      if(exp->child[0]->child[0]) env->n_t--;
      break;
    }
    case TN_STMT_WHILE:{
      Count_n_t(env, exp->child[0]);
      Count_n_t(env, exp->child[1]);
      break;
    }
    case TN_STMT_IF:{
      Count_n_t(env, exp->child[0]);
      Count_n_t(env, exp->child[1]);
      Count_n_t(env, exp->child[2]);
      break;
    }
    case TN_STMT_RETURN:{
      if(exp->child[0])
        Count_n_t(env, exp->child[0]);
      break;
    }
    default:{
      fprintf(stderr, "ERROR: unhandled countnt node %d\n", exp->type);
      break;
    }
  }
  return;
}

void SetArrSize(struct TreeNode* lval, struct Symbol* sym, struct Env* env){
  if(lval->type != TN_CLVAL && lval->type != TN_FUNCFP){
    fprintf(stderr, "ERROR: set a non-clval %s at L%d type%d\n", sym->name, sym->lineno, lval->type);
    exit(0);
  }
  if(lval->child[0] == NULL){//非数组
    sym->size = 0;
    sym->val = (int*)malloc(sizeof(int));
    return;
  }
  int size = 4;
  int dimension = 0;
  struct TreeNode* exp;
  exp = lval->child[0];
  while(exp){//printf("exp value = %d\n", CountConstExp(exp));
    size *= CountConstExp(exp, env);
    dimension++;
    if(exp->suc)
      exp = exp->suc;
    else{
      exp = exp->parent;
      break;
    }
  }
  exp = exp->child[0];
  sym->D_size = (int*)malloc(sizeof(int) * dimension);
  sym->dimension = dimension;
  for(int i = 0; i < dimension; ++i, exp = exp->suc)
    sym->D_size[i] = CountConstExp(exp, env);
  sym->size = size;
  sym->val = (int*)malloc(sizeof(int) * size);
}

int CountConstExp(struct TreeNode* exp, struct Env* env){//printf("counting exp (%d)\n", exp->idx);
  if(exp == NULL){
    fprintf(stderr, "ERROR: fail count const exp\n");
    exit(0);
  }
  if(exp->type == TN_NUMBER) return exp->value;
  if(exp->type == TN_LVAL){
    struct Symbol* sym;
    sym = FindSym(exp->name, env, exp->lineno);
    if(exp->child[0] == NULL) return sym->val[0];
    int* d = (int*)malloc(sizeof(int) * sym->dimension);
    //printf("counting const arr dimension %d\n", sym->dimension);
    exp = exp->child[0];
    for(int i = 0; i < sym->dimension; ++i, exp = exp->suc)
      d[i] = CountConstExp(exp, env);
    
      
    
    int idx = d[0];
    for(int i = 1; i < sym->dimension; ++i){
      idx *= sym->D_size[i];
      idx += d[i];
    }
    return sym->val[idx];
  }
  if(exp->type == TN_UEXP){
    if(strcmp(exp->child[0]->name, "-") == 0)
      return -CountConstExp(exp->child[1], env);
    if(strcmp(exp->child[0]->name, "!") == 0)
      return CountConstExp(exp->child[1], env) == 0 ? 1 : 0;
  }
  int val, val1, val2;
  val1 = CountConstExp(exp->child[0], env);
  val2 = CountConstExp(exp->child[1], env);
  if(strcmp(exp->name, "+") == 0) val = val1 + val2;
  if(strcmp(exp->name, "-") == 0) val = val1 - val2;
  if(strcmp(exp->name, "*") == 0) val = val1 * val2;
  if(strcmp(exp->name, "/") == 0) val = val1 / val2;
  if(strcmp(exp->name, "%") == 0) val = val1 % val2;
  return val;
}

void SetSymVal(struct Symbol* sym, struct TreeNode* val, struct Env* env){//setenv时确定const变量的值
  int type = val->type;
  int i = 0;//iterator
  int start = 0, end = sym->size, depth = -1;
  if(sym->size == 0){
    sym->val[0] = CountConstExp(val, env);
    return;
  }
  struct TreeNode* CurrentNode = val;
  while (CurrentNode){
    int flag = 0; 
    switch (type){
      case TN_CINITVAL:{
        depth++;//确认在哪个块内
        //define start 并补全,根据i depth 对齐
        int align = 1;
        for(int i = depth; i < sym->dimension; ++i)
          align *= sym->D_size[i];
        while(i < start) start += align;
        for(; i < start; ++i)
          sym->val[i] = 0;
        end = start + align;
        if(val->child[0] == NULL){
          for(i = start; i < end; ++i)
            sym->val[i] = 0;
        }
        else{
          CurrentNode = CurrentNode->child[0];
          flag = 1;
        }
        break;
      }
      default:{
        sym->val[i] = CountConstExp(val, env);
        break;
      }
    }
    if(flag) continue;
    if(CurrentNode->suc) CurrentNode = CurrentNode->suc;
    else{//完成一个块,返回上一个
      for(; i < end; ++i)
        sym->val[i] = 0;
      //修改end
      if(depth > 0){
        depth--;
        int align = 1;
        for(int i = depth; i < sym->dimension; ++i)
          align *= sym->D_size[i];
        end = (end / align + 1) * align;
        CurrentNode = CurrentNode->parent->suc;
      }
      else break;
    }
  }
}

