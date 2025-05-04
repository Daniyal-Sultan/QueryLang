#include "ast.h"
#include <stdio.h>
#include <string.h>

void generate_python(AstNode *root) {
    printf("import pandas as pd\n\n");
    printf("# Input data (replace with your actual data source)\n");
    printf("df = pd.DataFrame({\n");
    printf("    'col1': [1, 2, 3],\n");
    printf("    'col2': ['A', 'B', 'C'],\n");
    printf("    'col3': [100, 200, 300]\n");
    printf("})\n\n");

    printf("# Generated operations\n");
    while (root != NULL) {
        switch (root->type) {
            case NODE_SELECT: {
                char **columns = (char **)root->data;
                printf("# SELECT operation\n");
                printf("df = df[[");
                for (int i = 0; columns[i] != NULL; i++) {
                    printf("'%s'%s", columns[i], columns[i+1] ? ", " : "");
                }
                printf("]]\n");
                break;
            }

            case NODE_FILTER: {
                FilterData *filter = (FilterData *)root->data;
                printf("# FILTER operation\n");
                printf("df = df[df['%s'] %s %d]\n", 
                       filter->column, filter->op, filter->value);
                break;
            }

            case NODE_AGGREGATE: {
                AggregateData *agg = (AggregateData *)root->data;
                printf("# AGGREGATE operation\n");
                if (strcmp(agg->func, "COUNT") == 0) {
                    printf("df = df.groupby('%s').size().reset_index(name='count')\n", agg->column);
                } else {
                    printf("df = df.groupby('%s').agg({'%s': '%s'})\n", 
                           agg->column, agg->column, agg->func);
                }
                break;
            }

            default:
                fprintf(stderr, "Warning: Unknown node type %d\n", root->type);
        }
        root = root->next;
    }

    printf("\n# Output results\n");
    printf("print(df)\n");
    printf("df.to_csv('output.csv', index=False)\n");
}
