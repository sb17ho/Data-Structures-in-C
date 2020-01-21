struct Node{
    struct Node *left;
    int value;
    struct Node *right;
};

typedef struct Node node;

node * removeEle(node *root, int value);
node * leftMost(node *root);
node *createNode();
void add(node **root, int value);
void preOrder(node *root);
void postOrder(node *root);
void inOrder(node *root);
