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
   node *root = NULL;
    add(&root, 10);
    add(&root, 20);
    add(&root, 5);
    add(&root, 6);
    add(&root, 2);
    add(&root, 23);
    add(&root, 12);
    root = removeEle(root, 5);
    inOrder(root);
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

void preOrder(node *root){

    if(root == NULL)return;

    printf("%d\n", root->value);
    if(root->left != NULL) preOrder(root->left);
    if(root->right != NULL) preOrder(root->right);
} 

void postOrder(node *root){

    if(root == NULL)return;

    if(root->left != NULL) postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    printf("%d\n", root->value);
} 


void inOrder(node *root){

    if(root == NULL)return;

    if(root->left != NULL) inOrder(root->left);
    printf("%d\n", root->value);
    if(root->right != NULL) inOrder(root->right);
} 


void add(node **root, int value){
    if((*root) == NULL){
        (*root) = createNode();
        (*root)->value = value;
    }

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
}
