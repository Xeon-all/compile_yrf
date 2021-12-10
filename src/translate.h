#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

int T_idx;
int t_idx;
int p_idx;
int l_idx;

void InitTrans();

int ToEeyore(struct TreeNode*, struct Env*, FILE*, char*);

int EnvDeclare(struct Env*, FILE*, char*);

// void SetArrInitVal(int, struct TreeNode*, int*, int, int, FILE*);