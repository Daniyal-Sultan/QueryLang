%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern FILE *yyin;
void yyerror(const char *s);
%}

%union {
    char *str;
    int num;
    struct AstNode *node;
}

/* Add ALL tokens used in lexer.l */
%token SELECT FILTER AGGREGATE JOIN
%token GROUPBY AS LPAREN RPAREN COMMA
%token GT LT EQ
%token <str> IDENTIFIER
%token <num> NUMBER

%type <node> program operation_list operation select_op filter_op aggregate_op column_list
