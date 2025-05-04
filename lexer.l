%{
#include "parser.tab.h"
#include "ast.h"
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap

%%
SELECT      { return SELECT; }
FILTER      { return FILTER; }
AGGREGATE   { return AGGREGATE; }
JOIN        { return JOIN; }
GROUP\s+BY  { return GROUPBY; }
AS          { return AS; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
">"         { return GT; }
"="         { return EQ; }
"<"         { return LT; }
","         { return COMMA; }
"("         { return LPAREN; }
")"         { return RPAREN; }
[\n\t ]+    { /* ignore whitespace */ }
.           { fprintf(stderr, "Invalid token: %s\n", yytext); }
%%