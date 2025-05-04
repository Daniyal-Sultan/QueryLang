CC = gcc
FLEX = flex
BISON = bison

all: querylang

querylang: lexer.yy.c parser.tab.c ast.c codegen.c main.c
    $(CC) -o $@ $^

lexer.yy.c: lexer.l
    $(FLEX) -o lexer.yy.c lexer.l

parser.tab.c: parser.y
    $(BISON) -d parser.y -o parser.tab.c

clean:
    rm -f *.yy.c *.tab.* querylang *.o