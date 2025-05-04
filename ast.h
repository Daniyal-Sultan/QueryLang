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

AstNode* ast_create_select(char **columns);
AstNode* ast_create_filter(char *column, char *op, int value);
AstNode* ast_create_aggregate(char *column, char *func);
// ... Other helper functions