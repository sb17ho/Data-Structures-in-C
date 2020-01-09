#include<stdio.h>
#include<stdlib.h>

// Lower number means higher priority
struct Node{
    int value;
    int priority;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->next = NULL;
    return node;
}

void addItemsByPriority(int val, int *size, int prio){
    struct Node *temp;
    temp = createNode();
    temp->value = val;
    temp->priority = prio;

    if (head == NULL){    
        head = temp;
        *size = *size + 1;
    }else{
        struct Node *p = head;
        struct Node *q = NULL;
        while(p != NULL){
            if(p->priority > prio) break;
            q = p;    
            p = p->next;
        }
        if(q == NULL){
            struct Node *save = head;
            head = temp;
            temp->next = save;
        }else{
            struct Node *save = p;
            q->next = temp;
            temp->next = save;
        }
        *size = *size + 1;    
    }
}

int removeFirstItem(){
    int temp = head->value;
    struct Node *p = head->next;
    head = p;
    return temp;
}

int main(){
    int size = 0;

    addItemsByPriority(5, &size, 1);
    addItemsByPriority(1, &size, 0);
    addItemsByPriority(6, &size, 4);
    addItemsByPriority(7, &size, 2);
    addItemsByPriority(9, &size, 3);
    addItemsByPriority(10, &size, 6);
    addItemsByPriority(11, &size, 5);

    struct Node *q = head;

    while(q != NULL){
        printf("Value: %d Priority: %d\n", q->value, q->priority);
        q = q->next;
    }
 
    return 0;
}