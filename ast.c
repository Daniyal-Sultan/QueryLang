#include "ast.h"
#include <stdlib.h>
#include <string.h>

// Global AST root (used by get_ast_root())
static AstNode *ast_root = NULL;

// Helper structure for filter operations
typedef struct {
    char *column;
    char *op;
    int value;
} FilterData;

// Helper structure for aggregate operations
typedef struct {
    char *column;
    char *func;
} AggregateData;

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

AstNode* ast_append_column(AstNode *list, char *col) {
    // Get current columns array
    char **old_columns = (char **)list->data;
    
    // Count existing columns
    int count = 0;
    while (old_columns[count] != NULL) count++;
    
    // Allocate new array with space for new column
    char **new_columns = malloc((count + 2) * sizeof(char *));
    
    // Copy old columns
    for (int i = 0; i < count; i++) {
        new_columns[i] = old_columns[i];
    }
    
    // Add new column and NULL terminator
    new_columns[count] = strdup(col);
    new_columns[count+1] = NULL;
    
    // Replace old array and free it
    free(old_columns);
    list->data = new_columns;
    
    return list;
}

AstNode* ast_create_aggregate(char *column, char *func) {
    // Allocate aggregate data
    AggregateData *data = malloc(sizeof(AggregateData));
    data->column = strdup(column);
    data->func = strdup(func);

    // Create AST node
    AstNode *node = malloc(sizeof(AstNode));
    node->type = NODE_AGGREGATE;
    node->data = data;
    node->next = NULL;
    return node;
}

AstNode* ast_create_column_list(char *col) {
    // Create array with 2 slots (column + NULL terminator)
    char **columns = malloc(2 * sizeof(char *));
    columns[0] = strdup(col);
    columns[1] = NULL;

    // Create AST node
    AstNode *node = malloc(sizeof(AstNode));
    node->type = NODE_SELECT;
    node->data = columns;
    node->next = NULL;
    return node;
}

AstNode* ast_create_filter(char *column, char *op, int value) {
    // Allocate filter data
    FilterData *data = malloc(sizeof(FilterData));
    data->column = strdup(column);
    data->op = strdup(op);
    data->value = value;

    // Create AST node
    AstNode *node = malloc(sizeof(AstNode));
    node->type = NODE_FILTER;
    node->data = data;
    node->next = NULL;
    return node;
}

/* Implement other creation functions similarly */

AstNode* get_ast_root(void) {
    return ast_root;
}
