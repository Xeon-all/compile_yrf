#include <stdio.h>
#include "symtab.h"

#define TN_MAX_CHILD_NUMBER 3

#define TN_CDECL 0
#define TN_CDEF 1
#define TN_ROOT 2
#define TN_VOID 3
#define TN_CLVAL 4
#define TN_CINITVAL 5
#define TN_NUMBER 6
// #define TN_PEXP 7
#define TN_UEXP 8
#define TN_AEXP 9
#define TN_MEXP 10
// #define TN_CEXP 11
#define TN_STMT_RETURN 12
#define TN_VDECL 13
#define TN_VDEF 14
#define TN_INITVAL 15
#define TN_FUNCDEF_INT 16
#define TN_FUNCDEF_VOID 17
#define TN_BLOCK 18
#define TN_LVAL 19
#define TN_STMT_ASSIGN 20
#define TN_FUNCFP 21
#define TN_UOP 22
#define TN_STMT_IF 23
#define TN_STMT_WHILE 24
#define TN_STMT_BREAK 25
#define TN_STMT_CONTINUE 26
#define TN_REXP 27
#define TN_EEXP 28
#define TN_LAEXP 29
#define TN_LOEXP 30


#define CN_CDECL 1
#define CN_CDEF 2
#define CN_ROOT 1
#define CN_VOID 0
#define CN_CLVAL 1
#define CN_CINITVAL 1
#define CN_NUMBER 0
// #define CN_PEXP 1
#define CN_UEXP 2
#define CN_AEXP 2
#define CN_MEXP 2
// #define CN_CEXP 1
#define CN_STMT_RETURN 1
#define CN_VDECL 1
#define CN_VDEF 2
#define CN_INITVAL 1
#define CN_FUNCDEF_INT 2
#define CN_FUNCDEF_VOID 2
#define CN_BLOCK 1
#define CN_LVAL 1
#define CN_STMT_ASSIGN 2
#define CN_FUNCFP 1
#define CN_UOP 0
#define CN_STMT_IF 3
#define CN_STMT_WHILE 2
#define CN_STMT_BREAK 0
#define CN_STMT_CONTINUE 0
#define CN_REXP 2
#define CN_EEXP 2
#define CN_LAEXP 2
#define CN_LOEXP 2

struct Env{
  int lineno;
  int idx;
  int n_t;
  struct Env* child;
  struct Env* parent;
  struct Env* suc;
  struct Symbol* head;
  struct Symbol* P_head;
};

int n_env;
int n_treenode;
int T_idx;
int t_idx;
int p_idx;
int l_idx;
int cn_func;
struct Env* RootEnv;


struct TreeNode {
  char* name;
  int value;
  int type;
  int lineno;
  int idx;
  int childNum;
  struct TreeNode* parent;
  struct TreeNode* pre;
  struct TreeNode* suc;
  struct TreeNode* child[TN_MAX_CHILD_NUMBER];
};

struct TreeNode* new_node(int, int, char*);

struct Env* new_env(int);

void PrintTreeNode(struct TreeNode*, char*, FILE*);

void PrintTree(struct TreeNode *, int, FILE*);

void PrintEnvNode(struct Env*, char*, FILE*);

void PrintEnv(struct Env*, int, FILE*);

void SetEnv(struct TreeNode*, struct Env*);

void InitEnv();

struct Symbol* FindSym(char*, struct Env*, int);

void Count_n_t(struct Env*, struct TreeNode*);

void SetArrSize(struct TreeNode*, struct Symbol*, struct Env*);

int CountConstExp(struct TreeNode*, struct Env*);

void SetSymVal(struct Symbol* sym, struct TreeNode* val, struct Env* env);