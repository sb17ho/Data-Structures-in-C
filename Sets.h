#include<stdlib.h>
#include<stdio.h>

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
void print(node *root);
int exist(node *root, int value);

