%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sysY.tab.h"

int lineno;
int octtoi(const char*);
int hextoi(const char*);
//还需要做注释的处理
%}

digit [0-9]
nonzero-digit [1-9]
number 0|{nonzero-digit}{digit}*
oct-digit [0-7]
oct-number 0{oct-digit}+
hex-digit [0-9a-fA-F]
hex-number 0(x|X){hex-digit}+
int {hex-number}|{number}|{oct-number}

nondig [_a-zA-Z]
id {nondig}({digit}|{nondig})*
newline \n
space [" "\t]+

%%

"const" {return CONST;}
"int" {return INT;}
"void" {return VOID;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"return" {return RETURN;}

"," {return COMMA;}
";" {return EOL;}
"(" {return LPRN;}
")" {return RPRN;}
"[" {return LBRA;}
"]" {return RBRA;}
"{" {return LCUR;}
"}" {return RCUR;}
"=" {return ASSIGN;}

"+" {return PLUS;}
"-" {return MINUS;}
"!" {return NO;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"<" {return LS;}
">" {return GR;}
"<=" {return LSE;}
">=" {return GRE;}
"==" {return EQ;}
"!=" {return NEQ;}
"&&" {return AND;}
"||" {return OR;}

"//"[^\n]*	{;}
"/*"[^"*/"]* {;}

{newline} {lineno++;}
{space} {;}

{number} {yylval.value = atoi(yytext);return INT_CONST;}
{oct-number} {yylval.value = octtoi(yytext); return INT_CONST;}
{hex-number} {yylval.value = hextoi(yytext); return INT_CONST;}
{id} {yylval.name = strdup(yytext); return IDENT;}



. {return ERROR;}

%%
int octtoi(const char* str){
	int exp = 1;
	int dec = 0;
	for(int i = strlen(str) - 1; i > 0; i --){
		dec += (str[i] - '0') * exp;
		exp *= 8;
	}
	return dec;
}

int hextoi(const char* str){
	int exp = 1;
	int dec = 0;
	int digit;
	for(int i = strlen(str) - 1; i > 1; i --){
		switch(str[i]){
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				digit = str[i] - 'a' + 10;
				break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				digit = str[i] - 'A' + 10;
				break;
			default:
				digit = str[i] - '0';
				break;
		}
		dec += digit * exp;
		exp *= 16;
	}
	return dec;
}

int yywrap() {
	return 1;
}

// void writeout(int c){
//   switch(c){
//   	case CONST: fprintf(yyout, "(CONST, \"%s\") ", yytext);break;
//   	case INT: fprintf(yyout, "(INT, \"%s\") ", yytext);break;  	  
//     case VOID: fprintf(yyout, "(VOID, \"%s\") ", yytext);break;
//     case IF: fprintf(yyout, "(IF, \"%s\") ", yytext);break;
//     case ELSE: fprintf(yyout, "(ELSE, \"%s\") ", yytext);break;
//     case WHILE: fprintf(yyout, "(WHILE, \"%s\") ", yytext);break;
// 		case BREAK: fprintf(yyout, "(BREAK, \"%s\") ", yytext);break;
// 		case CONTINUE: fprintf(yyout, "(CONTINUE, \"%s\") ", yytext);break;
// 		case RETURN: fprintf(yyout, "(RETURN, \"%s\") ", yytext);break;
// 		case COMMA: fprintf(yyout, "(COMMA, \"%s\") ", yytext);break;
// 		case EOL: fprintf(yyout, "(EOL, \"%s\") ", yytext);break;
// 		case LPRN: fprintf(yyout, "(LPRN, \"%s\") ", yytext);break;
// 		case RPRN: fprintf(yyout, "(RPRN, \"%s\") ", yytext);break;
// 		case LBRA: fprintf(yyout, "(LBRA, \"%s\") ", yytext);break;
// 		case RBRA: fprintf(yyout, "(RBRA, \"%s\") ", yytext);break;
// 		case LCUR: fprintf(yyout, "(LCUR, \"%s\") ", yytext);break;
// 		case RCUR: fprintf(yyout, "(RCUR, \"%s\") ", yytext);break;
// 		case ASSIGN: fprintf(yyout, "(ASSIGN, \"%s\") ", yytext);break;
// 		case PLUS: fprintf(yyout, "(PLUS, \"%s\") ", yytext);break;
// 		case MINUS: fprintf(yyout, "(MINUS, \"%s\") ", yytext);break;
// 		case NO: fprintf(yyout, "(NO, \"%s\") ", yytext);break;
// 		case MUL: fprintf(yyout, "(MUL, \"%s\") ", yytext);break;
// 		case DIV: fprintf(yyout, "(DIV, \"%s\") ", yytext);break;
// 		case MOD: fprintf(yyout, "(MOD, \"%s\") ", yytext);break;
// 		case LS: fprintf(yyout, "(LS, \"%s\") ", yytext);break;
// 		case GR: fprintf(yyout, "(GR, \"%s\") ", yytext);break;
// 		case LSE: fprintf(yyout, "(LSE, \"%s\") ", yytext);break;
// 		case GRE: fprintf(yyout, "(GRE, \"%s\") ", yytext);break;
// 		case EQ: fprintf(yyout, "(EQ, \"%s\") ", yytext);break;
// 		case NEQ: fprintf(yyout, "(NEQ, \"%s\") ", yytext);break;
// 		case AND: fprintf(yyout, "(AND, \"%s\") ", yytext);break;
// 		case OR: fprintf(yyout, "(OR, \"%s\") ", yytext);break;
// 		case INT_CONST: fprintf(yyout, "(INT_CONST, \"%s\") ", yytext);break;
// 		case IDENT: fprintf(yyout, "(IDENT, \"%s\") ", yytext);break;
//     case 100: fprintf(yyout, "\n");break;
//     default:break;
//   }
//   return;
// }

// int main(int argc, char** argv){
// 	int c,j=0;
// 	if (argc>=2){
// 	  if ((yyin = fopen(argv[1], "r")) == NULL){
// 	    printf("Can't open file %s\n", argv[1]);
// 	    return 1;
// 	  }
// 	  if (argc>=3){
// 	    yyout=fopen(argv[2], "w");
// 	  }
// 	}
// 	/* yyin和yyout是lex中定义的输入输出文件指针，它们指明了
// 	 * lex生成的词法分析器从哪里获得输入和输出到哪里。
// 	 * 默认：键盘输入，屏幕输出。 
// 	 */
// 	while (c = yylex()){
// 		writeout(c);
// 		j++;
// 		if (j%5 == 0) writeout(100);
// 	}
// 	if(argc>=2){
// 	  fclose(yyin);
// 	  if (argc>=3) fclose(yyout);
// 	}
// 	return 0;
// }


