#include "ast.h"
#include <stdio.h>

void generate_python(AstNode *root) {
    printf("import pandas as pd\n\ndf = pd.read_csv('input.csv')\n");
    
    while (root != NULL) {
        switch (root->type) {
            case NODE_SELECT: {
                char **cols = (char**)root->data;
                printf("df = df[[");
                for (int i = 0; cols[i] != NULL; i++) {
                    printf("'%s'%s", cols[i], cols[i+1] ? ", " : "");
                }
                printf("]]\n");
                break;
            }
            case NODE_FILTER: {
                // Implement filter code generation
                break;
            }
            // Add other cases
        }
        root = root->next;
    }
    printf("\ndf.to_csv('output.csv', index=False)\n");
}
