struct Node{
    struct Node *left;
    int value;
    struct Node *right;
};

typedef struct Node node;

void add(node **root, int value);
void traversal(node *root);
