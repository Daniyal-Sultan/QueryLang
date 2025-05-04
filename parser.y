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

%start program

%%

program:
    operation_list { $$ = $1; }
;

operation_list:
    operation { $$ = ast_create_operation_list($1); }
    | operation_list operation { $$ = ast_append_operation($1, $2); }
;

operation:
    select_op
    | filter_op
    | aggregate_op
;

select_op:
    SELECT column_list { $$ = ast_create_select($2); }
;

column_list:
    IDENTIFIER { $$ = ast_create_column_list($1); }
    | column_list COMMA IDENTIFIER { $$ = ast_append_column($1, $3); }
;

filter_op:
    FILTER IDENTIFIER GT NUMBER { $$ = ast_create_filter($2, ">", $4); }
;

aggregate_op:
    AGGREGATE IDENTIFIER IDENTIFIER { $$ = ast_create_aggregate($2, $3); }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
