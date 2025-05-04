#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"

extern FILE* yyin;

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.ql>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Could not open input file");
        return 1;
    }

    // Parse the input file
    if (yyparse() != 0) {
        fprintf(stderr, "Parsing failed\n");
        return 1;
    }

    // Generate Python code (assuming you have this function)
    generate_python(get_ast_root());
    
    fclose(yyin);
    return 0;
}