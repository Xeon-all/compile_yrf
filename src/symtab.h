#include <stdio.h>

struct Symbol{
  int lineno;
  int size;
  int E_idx;
  int dimension;
  int* val;
  int* D_size;
  char* EType;
  char* name;
  char* Type;
  struct Symbol* suc;
  struct Env* funcEnv;
};

struct Symbol* funclisthead;

struct Symbol* new_symbol(int, char*, char*, char*);

void PrintSymtab(struct Symbol*, char*, FILE*);
