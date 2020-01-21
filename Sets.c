#include"Sets.h"

node *createNode(){
    node *node = malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
   node *root = NULL;
    add(&root, 10);
    add(&root, 20);
    add(&root, 5);
    add(&root, 5);
    // add(&root, 2);
    // add(&root, 23);
    // add(&root, 12);
    // root = removeEle(root, 5);
    traversal(root);
}

void add(node **root, int value){
    if((*root) == NULL){
        (*root) = createNode();
        (*root)->value = value;
    }else if(exist((*root), value) == 0){
        if((*root)->value > value){
            if((*root)->left == NULL){
                (*root)->left = createNode();
                (*root)->left->value = value;
            }else{
                add(&((*root)->left), value);
            }
        }else if((*root)->value < value){
            if((*root)->right == NULL){
                (*root)->right = createNode();
                (*root)->right->value = value;
            }else{
                add(&((*root)->right), value);
            }
        }
    }else{
        printf("The value already exit\n");
    }
}

node * removeEle(node *root, int value){
    if(root == NULL){
        return NULL;
    }else{
        if(value < root->value && root->left != NULL){
            root->left = removeEle(root->left, value);
        }else if(value > root->value && root->right != NULL){
            root->right = removeEle(root->right, value);
        }else{
            if(root->left == NULL && root->right == NULL){
               return NULL;
            }else if(root->left == NULL && root->right != NULL){
                return root->right;
            }else if(root->left != NULL && root->right == NULL){
                return root->left;
            }
            else{
                node * check = leftMost(root->right);
                root->value = check->value;
                root->right = removeEle(root->right, check->value);
                return root;
            }
        }
    }
}

node * leftMost(node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

void traversal(node *root){

    if(root == NULL)return;

    printf("%d\n", root->value);
    if(root->left != NULL) traversal(root->left);
    if(root->right != NULL) traversal(root->right);
} 

int exist(node *root, int value){
    int check = 0;
    if(root == NULL) return check;
    if(root->value == value){
        check=1;
    }
    if(value < root->value) exist(root->left, value);
    if(value > root->value) exist(root->right, value);
    return check;
} 


