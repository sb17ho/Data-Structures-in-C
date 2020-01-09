#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->next = NULL;
    return node;
}

void addItems(int val, int *size){
    struct Node *temp;
    temp = createNode();
    temp->value = val;

    if (head == NULL){    
        head = temp;
        *size = *size + 1;
    }else{
        struct Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }

        p->next = temp;    
        *size = *size + 1;    
    }
}

// void sort(){
//     struct Node *sorted = NULL;

//     struct Node *current = head;
//     while(current != NULL){
//         struct Node *p = current->next;
//         // InsertSorted(&sorted, current);
//         current = p;
//     }
// }

// void InsertSorted(struct Node **node, struct Node *p){
    
// }

int removeFirstItem(){
    int temp = head->value;
    struct Node *p = head->next;
    head = p;
    return temp;
}

int removeLastElement(){
    struct Node *p = head->next;
    struct Node *q = head;

    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }

    int temp = p->value;
    q->next = NULL;

    return temp;
}

int removeByValue(int val){
    struct Node *p = head->next;
    struct Node *q = head;
    struct Node *r = NULL;

    while(q->value != val){
        r=q;
        q = q->next;
        p = p->next;
    }
    int temp = q->value;
    r->next = p;
    return temp;
}

int main(){
    // head = malloc(sizeof(struct Node));
    int size = 0;

    addItems(10, &size);
    addItems(20, &size);
    addItems(15, &size);
    addItems(5, &size);

    printf("New Size: %d\n", size);
    // printf("Head value: %d", head->value);
    struct Node *q = head;

    while(q != NULL){
        printf("%d ", q->value);
        q = q->next;
    }
    printf("\n");
    // sort();
    removeByValue(20);

    q = head;
    while(q != NULL){
        printf("%d ", q->value);
        q = q->next;
    }
    printf("\n");

    return 0;
}