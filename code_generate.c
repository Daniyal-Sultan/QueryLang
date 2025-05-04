#include "ast.h"
#include <stdio.h>

void generate_python(AstNode *root) {
    printf("import pandas as pd\n\ndf = pd.read_csv('input.csv')\n");
    while (root != NULL) {
        switch (root->type) {
            case NODE_SELECT:
                // Generate SELECT code
                printf("df = df[%s]\n", (char*)root->data);
                break;
            case NODE_FILTER:
                // Generate FILTER code
                printf("df = df[df['%s'] > %d]\n", ...);
                break;
            // ... Handle other nodes
        }
        root = root->next;
    }
    printf("\ndf.to_csv('output.csv', index=False)\n");
}