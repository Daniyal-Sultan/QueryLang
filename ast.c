#include "ast.h"
#include <stdlib.h>
#include <string.h>

static AstNode *ast_root = NULL;

AstNode* ast_create_operation_list(AstNode *op) {
    return op;
}

AstNode* ast_append_operation(AstNode *list, AstNode *op) {
    AstNode *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = op;
    return list;
}

AstNode* ast_create_select(char **columns) {
    AstNode *node = malloc(sizeof(AstNode));
    node->type = NODE_SELECT;
    node->data = columns;
    node->next = NULL;
    return node;
}

/* Implement other creation functions similarly */

AstNode* get_ast_root(void) {
    return ast_root;
}
