#include"Stack.h"

int size = 0;
void* *arr;

#define int_print *(int*)

int main(){
    arr = malloc(sizeof(void*)*10);
    int a[] = {10,20,30,40};
    push(&a[0]);
    push(&a[1]);
    push(&a[2]);
    push(&a[3]);
    // push(&a[4]);
    printf("removed %d \n", *(int*)pop());
    printf("Top: %d\n", *(int*)top());
    print("int");
}

void push(void* value){
    if(0 == size%10){
        int newsize = size + 10;
        arr = realloc(arr, sizeof(void*)*newsize);
    }
    arr[size++] = value;
}

void* pop(){
    void* temp = arr[--size];
    return temp;
}

void* top(){
    return arr[(size-1)];
}

void print(char * what_type){
    for(size_t i=0; i<size; i++){
        if(strcmp(what_type,"int") == 0){
             printf("%d ", int_print(arr[i]));
        }
    }
    printf("\n");
}