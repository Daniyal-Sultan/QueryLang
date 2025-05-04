#ifndef AST_H
#define AST_H

typedef enum {
    NODE_SELECT,
    NODE_FILTER,
    NODE_AGGREGATE
} NodeType;

typedef struct AstNode {
    NodeType type;
    void *data;
    struct AstNode *next;
} AstNode;

/* AST Creation */
AstNode* ast_create_operation_list(AstNode *op);
AstNode* ast_append_operation(AstNode *list, AstNode *op);
AstNode* ast_create_select(char **columns);
AstNode* ast_create_filter(char *column, char *op, int value);
AstNode* ast_create_aggregate(char *column, char *func);
AstNode* ast_create_column_list(char *col);
AstNode* ast_append_column(AstNode *list, char *col);

/* Helpers */
AstNode* get_ast_root(void);
void generate_python(AstNode *root);

#endif
