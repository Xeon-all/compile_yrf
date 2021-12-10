#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symtab.h"

struct Symbol* new_symbol(int lineno, char* name, char* Etype, char* type){
  struct Symbol* node = (struct Symbol*)malloc(sizeof(struct Symbol));
  node->size = 0;
  node->lineno = lineno;
  node->name = name;
  node->suc = NULL;
  node->EType = Etype;
  node->E_idx = -1;
  node->Type = type;
  node->dimension = -1;
  node->D_size = NULL;
  node->val = NULL;
  node->funcEnv = NULL;
  // printf("create symbol %s at L(%d)\n", name, lineno + 1);
  return node;
}

void PrintSymtab(struct Symbol* sym, char* arg_prefix, FILE* f){
  if(sym == NULL){
    fprintf(f, "no symbols\n");
    return;
  }
  char* prefix;
	if (arg_prefix == NULL)
		prefix = _strdup("");
	else
		prefix = _strdup(arg_prefix);
  fprintf(f, "%s-symbol name:%s Ename:%s%d", prefix, sym->name, sym->EType, sym->E_idx);
  if(sym->size != 0)
    fprintf(f, " arrsize:%d", sym->size);
  if(strcmp(sym->Type, "c") == 0){
    int size = sym->size / 4;
    fprintf(f, " const val = %d", sym->val[0]);
    for(int i = 1; i < size; ++i)
      fprintf(f, " %d", sym->val[i]);
  }
    
  fprintf(f, "\n");
  if(sym->suc)
    PrintSymtab(sym->suc, arg_prefix, f);
}
