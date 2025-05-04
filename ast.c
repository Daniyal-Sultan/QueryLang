#include "ast.h"
#include <stdlib.h>

AstNode* ast_create_select(char **columns) {
    AstNode *node = malloc(sizeof(AstNode));
    node->type = NODE_SELECT;
    node->data = columns;
    node->next = NULL;
    return node;
}
// ... Implement other node creators