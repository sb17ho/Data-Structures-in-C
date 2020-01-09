#include<stdio.h>
#include<stdlib.h>
#include"Binarytree.h"

node *createNode(){
    node *node = malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    int size = 1;
    node *root = NULL;
    add(&root, 10);
    add(&root, 20);
    printf("%d\n", root->right->value);
    // add(&root, 5);
    // traversal(root);
}

void add(node **root, int value){
    if((*root) == NULL){
        (*root) = createNode();
        (*root)->value = value;
    }
    if((*root)->value >= value){
        add(&((*root)->left), value);
    }else if((*root)->value <= value){
        add(&((*root)->right), value);
    }
}

void traversal(node *root){
    if(root == NULL){
        return;
    }
    printf("%d\n", root->value);
    traversal(root->left);
    traversal(root->right);
}