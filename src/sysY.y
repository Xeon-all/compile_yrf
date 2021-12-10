%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "translate.h"

int yylex(void);
void yyerror(char*);

extern FILE* yyin;
extern FILE* yyout;
extern int lineno;
struct TreeNode* root;
char *input, *output;

//struct TreeNode* tempNode;
// %right ASSIGN
// %left AND OR
// %left EQ NEQ
// %left LS LSE GR GRE
// %left PLUS MINUS
// %left MUL MOD DIV
// %right NO
%}

%token CONST INT VOID IF ELSE WHILE BREAK CONTINUE RETURN
%token COMMA EOL LPRN RPRN LBRA RBRA LCUR RCUR ASSIGN
%token PLUS MINUS NO MUL DIV MOD LS GR LSE GRE EQ NEQ AND OR
%token <value> INT_CONST 
%token <name> IDENT
%token ERROR

%nonassoc IFX
%nonassoc ELSE

%type <node> CompUnit
%type <node> Decl ConstDecl ConstDef ConstInitVal VarDecl VarDef InitVal
%type <node> FuncDef FuncFParams FuncFParam
%type <node> Block BlockItem Stmt EmptyBlock
%type <node> Exp Cond LVal PrimaryExp Number UnaryExp UnaryOp FuncRParams MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp
%type <node> ConstDefList ConstLVal ConstInitValList VarDefList InitValList ConstSuffix

%union {
	int value;
	char* name;
	struct TreeNode* node;
};

%%

CompUnit : 
  CompUnit Decl{
		$1->suc = $2;
		$2->pre = $1;
		$$ = $2;
  }
  |Decl{
    struct TreeNode* tempNode;
    tempNode = new_node(TN_ROOT, lineno, NULL);
    tempNode->child[0] = $1;$1->parent = tempNode;
    root = tempNode;
  }
  |CompUnit FuncDef{
    $1->suc = $2;
		$2->pre = $1;
		$$ = $2;
  }
  |FuncDef{
    struct TreeNode* tempNode;
    tempNode = new_node(TN_ROOT, lineno, NULL);
    tempNode->child[0] = $1;$1->parent = tempNode;
    root = tempNode;
  };

Decl :
  ConstDecl{
    $$ = $1;
  }
  |VarDecl{
    $$ = $1;
  };

ConstDecl :
  CONST INT ConstDefList EOL{
    $$ = new_node(TN_CDECL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = $3;
    while(tempNode->pre){
      tempNode->parent = $$;
      tempNode = tempNode->pre;
    }
    $$->child[0] = tempNode; tempNode->parent = $$;
  };

ConstDefList :
  ConstDef{
    $$ = $1;
  }
  |ConstDefList COMMA ConstDef{
    $1->suc = $3;
    $3->pre = $1;
    $$ = $3;
  };

ConstDef :
  ConstLVal ASSIGN ConstInitVal{
    $$ = new_node(TN_CDEF, lineno, $1->name);
    $$->child[0] = $1; $1->parent = $$;
    $$->child[1] = $3; $3->parent = $$;
  };

ConstLVal :
  IDENT ConstSuffix{
    $$ = new_node(TN_CLVAL, lineno, strdup($1));
    if($2){
      $2->parent = $$;
      struct TreeNode* tempNode;
      tempNode = $2;
      while(tempNode->pre){
        tempNode = tempNode->pre;
      }
      $$->child[0] = tempNode; tempNode->parent = $$;
    }
  };

ConstInitVal :
  ConstExp{
    $$ = $1;
  }
  |LCUR ConstInitValList RCUR{
    $$ = new_node(TN_CINITVAL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = $2;
    while(tempNode->pre){
      tempNode->parent = $$;
      tempNode = tempNode->pre;
    }
    $$->child[0] = tempNode; tempNode->parent = $$;
  }
  |EmptyBlock{
    $$ = new_node(TN_CINITVAL, lineno, NULL);
    $$->value = 0;
  };

ConstInitValList :
  ConstInitVal{
    $$ = $1;
  }
  |ConstInitValList COMMA ConstInitVal{
    $1->suc = $3;
    $3->pre = $1;
    $$ = $3;
  };

VarDecl :
  INT VarDefList EOL{
    $$ = new_node(TN_VDECL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = $2;
    while(tempNode->pre){
      tempNode->parent = $$;
      tempNode = tempNode->pre;
    }
    $$->child[0] = tempNode; tempNode->parent = $$;
  };

VarDefList :
  VarDef{
    $$ = $1;
  }
  |VarDefList COMMA VarDef{
    $1->suc = $3;
    $3->pre = $1;
    $$ = $3;
  };

VarDef :
  ConstLVal{
    $$ = new_node(TN_VDEF, lineno, $1->name);
    $$->child[0] = $1; $1->parent = $$;
  }
  |ConstLVal ASSIGN InitVal{
    $$ = new_node(TN_VDEF, lineno, $1->name);
    $$->child[0] = $1; $1->parent = $$;
    $$->child[1] = $3; $3->parent = $$;
  };

InitVal :
  Exp{
    $$ = $1;
  }
  |LCUR InitValList RCUR{
    $$ = new_node(TN_INITVAL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = $2;
    while(tempNode->pre){
      tempNode->parent = $$;
      tempNode = tempNode->pre;
    }
    $$->child[0] = tempNode; tempNode->parent = $$;
  }
  |EmptyBlock{
    $$ = new_node(TN_INITVAL, lineno, NULL);
    $$->value = 0;
  };

EmptyBlock :
  LCUR RCUR{};

InitValList :
  InitVal{
    $$ = $1;
  }
  |InitValList COMMA InitVal{
    $1->suc = $3;
    $3->pre = $1;
    $$ = $3;
  };

FuncDef :
  INT IDENT LPRN RPRN Block{
    $$ = new_node(TN_FUNCDEF_INT, lineno, $2);
    $$->child[0] = $5;$5->parent = $$;
  }
  |INT IDENT LPRN FuncFParams RPRN Block{
    $$ = new_node(TN_FUNCDEF_INT, lineno, $2);
    struct TreeNode* tempNode;
    tempNode = $4;
    while(tempNode->pre){
      tempNode->parent = $$;
      tempNode = tempNode->pre;
    }
    $$->child[0] = $6;$6->parent = $$;
    $$->child[1] = tempNode;tempNode->parent = $$;
  }
  |VOID IDENT LPRN RPRN Block{
    $$ = new_node(TN_FUNCDEF_VOID, lineno, $2);
    $$->child[0] = $5;$5->parent = $$;
  }
  |VOID IDENT LPRN FuncFParams RPRN Block{
    $$ = new_node(TN_FUNCDEF_VOID, lineno, $2);
    struct TreeNode* tempNode;
    tempNode = $4;
    while(tempNode->pre){
      tempNode->parent = $$;
      tempNode = tempNode->pre;
    }
    $$->child[0] = $6;$6->parent = $$;
    $$->child[1] = tempNode;tempNode->parent = $$;
  };

FuncFParams :
  FuncFParam{
    $$ = $1;
  }
  |FuncFParams COMMA FuncFParam{
    $1->suc = $3;
    $3->pre = $1;
    $$ = $3;
  };

FuncFParam :
  INT IDENT{
    $$ = new_node(TN_FUNCFP, lineno, NULL);
    $$->name = $2;
  }
  |INT IDENT LBRA RBRA ConstSuffix{
    $$ = new_node(TN_FUNCFP, lineno, NULL);
    $$->name = $2;
    struct TreeNode* tempNode;
    tempNode = $5;
    if(tempNode){
      while(tempNode){
        tempNode->parent = $$;
        tempNode = tempNode->pre;
      }
    }
    $$->child[0] = $5;
  };

ConstSuffix :
  ConstSuffix LBRA ConstExp RBRA{
    if($1){
      $1->suc = $3;
    }
    $3->pre = $1;
    $$ = $3;
  }
  | {$$ = NULL;};

Block :
  LCUR BlockItem RCUR{
    $$ = new_node(TN_BLOCK, lineno, NULL);
    struct TreeNode* tempNode;
    if($2){
      tempNode = $2;
      while(tempNode->pre){
        tempNode->parent = $$;
        tempNode = tempNode->pre;
      }
      tempNode->parent = $$;
    }
    else tempNode = $2;
    $$->child[0] = tempNode;
  };

BlockItem :
  BlockItem Decl{
    if($1){
      $1->suc = $2;
    }
    $2->pre = $1;
    $$ = $2;
  }
  |BlockItem Stmt{
    if($1){
      $1->suc = $2;
    }
    $2->pre = $1;
    $$ = $2;
  }
  |{$$ = NULL;};

Stmt :
  LVal ASSIGN Exp EOL{
    $$ = new_node(TN_STMT_ASSIGN, lineno, NULL);
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |EOL{}
  |Exp EOL{$$ = $1;}
  |Block{$$ = $1;}
  |IF LPRN Cond RPRN Stmt %prec IFX{
    $$ = new_node(TN_STMT_IF, lineno, NULL);
    $$->child[0] = $3;$3->parent = $$;
    $$->child[1] = $5;$5->parent = $$;
  }
  |IF LPRN Cond RPRN Stmt ELSE Stmt{
    $$ = new_node(TN_STMT_IF, lineno, NULL);
    $$->child[0] = $3;$3->parent = $$;
    $$->child[1] = $5;$5->parent = $$;
    $$->child[2] = $7;$7->parent = $$;
  }
  |WHILE LPRN Cond RPRN Stmt{
    $$ = new_node(TN_STMT_WHILE, lineno, NULL);
    $$->child[0] = $3;$3->parent = $$;
    $$->child[1] = $5;$5->parent = $$;
  }
  |BREAK EOL{
    $$ = new_node(TN_STMT_BREAK, lineno, NULL);
  }
  |CONTINUE EOL{
    $$ = new_node(TN_STMT_CONTINUE, lineno, NULL);
  }
  |RETURN EOL{
    $$ = new_node(TN_STMT_RETURN, lineno, NULL);
  }
  |RETURN Exp EOL{
    $$ = new_node(TN_STMT_RETURN, lineno, NULL);
    $$->child[0] = $2;$2->parent = $$;
  };

Exp :
  AddExp{
    $$ = $1;
  };

Cond :
  LOrExp{
    $$ = $1;
  };

LVal :
  IDENT{
    $$ = new_node(TN_LVAL, lineno, $1);
  }
  |LVal LBRA Exp RBRA{
    if($1->child[0]){
      struct TreeNode* tempNode;
      tempNode = $1->child[0];
      while(tempNode->suc){
        tempNode = tempNode->suc;
      }
      tempNode->suc = $3;$3->pre = tempNode;
    }
    else{
      $1->child[0] = $3;
    }
    $3->parent = $1;
    $$ = $1;
  };

PrimaryExp :
  LPRN Exp RPRN{
    $$ = $2;
  }
  |LVal{
    $$ = $1;
  }
  |Number{
    $$ = $1;
  };

Number :
  INT_CONST{
    $$ = new_node(TN_NUMBER, lineno, NULL);
    $$->value = $1;
  };

UnaryExp :
  PrimaryExp{
    $$ = $1;
  }
  |IDENT LPRN RPRN{
    $$ = new_node(TN_UEXP, lineno, $1);
  }
  |IDENT LPRN FuncRParams RPRN{
    $$ = new_node(TN_UEXP, lineno, $1);
    struct TreeNode* tempNode;
    tempNode = $3;
    while(tempNode->pre){
      tempNode = tempNode->pre;
    }
    $$->child[1] = tempNode;tempNode->parent = $$;
  }
  |UnaryOp UnaryExp{
    if(strcmp($1->name, "+")){
      if($2->type == TN_UEXP){
        if($2->child[0] == NULL){
          $2->child[0] = $1;$1->parent = $2;
        }
        else{
          struct TreeNode* tempNode;
          tempNode = $2->child[0];
          while(tempNode->pre){
            tempNode = tempNode->pre;
          }
          tempNode->pre = $1;
          $1->suc = tempNode;
          $$ = $2;
        }
      }
      else{
        $$ = new_node(TN_UEXP, lineno, NULL);
        $$->child[0] = $1;$1->parent = $$;
        $$->child[1] = $2;$2->parent = $$;
      }
    }
    else{
      $$ = $2;
    }
  };

UnaryOp :
  PLUS{
    $$ = new_node(TN_UOP, lineno, "+");
  }
  |MINUS{
    $$ = new_node(TN_UOP, lineno, "-");
  }
  |NO{
    $$ = new_node(TN_UOP, lineno, "!");
  };

FuncRParams :
  Exp{
    $$ = $1;
  }
  |FuncRParams COMMA Exp{
    $1->suc = $3;
    $3->pre = $1;
    $$ = $3;
  };

MulExp :
  UnaryExp{
    $$ = $1;
  }
  |MulExp MUL UnaryExp{
    $$ = new_node(TN_MEXP, lineno, "*");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |MulExp DIV UnaryExp{
    $$ = new_node(TN_MEXP, lineno, "/");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |MulExp MOD UnaryExp{
    $$ = new_node(TN_MEXP, lineno, "%");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  };

AddExp :
  MulExp{
    $$ = $1;
  }
  |AddExp PLUS MulExp{
    $$ = new_node(TN_AEXP, lineno, "+");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |AddExp MINUS MulExp{
    $$ = new_node(TN_AEXP, lineno, "-");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  };

RelExp :
  AddExp{
    $$ = $1;
  }
  |RelExp LS AddExp{
    $$ = new_node(TN_REXP, lineno, "<");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |RelExp LSE AddExp{
    $$ = new_node(TN_REXP, lineno, "<=");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |RelExp GR AddExp{
    $$ = new_node(TN_REXP, lineno, ">");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |RelExp GRE AddExp{
    $$ = new_node(TN_REXP, lineno, ">=");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  };

EqExp :
  RelExp{
    $$ = $1;
  }
  |EqExp EQ RelExp{
    $$ = new_node(TN_EEXP, lineno, "==");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  }
  |EqExp NEQ RelExp{
    $$ = new_node(TN_EEXP, lineno, "!=");
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  };

LAndExp :
  EqExp{
    $$ = $1;
  }
  |LAndExp AND EqExp{
    $$ = new_node(TN_LAEXP, lineno, NULL);
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  };

LOrExp :
  LAndExp{
    $$ = $1;
  }
  |LOrExp OR LAndExp{
    $$ = new_node(TN_LOEXP, lineno, NULL);
    $$->child[0] = $1;$1->parent = $$;
    $$->child[1] = $3;$3->parent = $$;
  };

ConstExp :
  AddExp{
    $$ = $1;
  };

%%

void yyerror(char* s){
  extern char* yytext;
	fprintf(stderr, ">> ERROR@L%d: %s at %s\n", lineno, s, yytext);
	exit(-3);
}

int main(int argc, char** argv){
  fopen_s(&yyin, "testfile", "r");
  fopen_s(&yyout, "eeyore", "w");

  FILE* f;
  fopen_s(&f, "tree", "w");
  FILE* f1;
  fopen_s(&f1, "symtab", "w");

  n_treenode = 0;
  InitEnv();
  InitTrans();

  yyparse();

  PrintTree(root, 0, f);
  SetEnv(root, RootEnv);
  PrintEnv(RootEnv, 0, f1);
  ToEeyore(root, RootEnv, yyout, "");
	return 0;
}