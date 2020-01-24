#include"HashTable.h"

int main(){
    arr = calloc(size, sizeof(int));
    initialize();
    put(2);
    put(5);
    put(3);
    put(1);
    print();
}

void initialize(){
    for (size_t i = 0; i < size; i++){
        arr[i] = __INT_MAX__;
    }
}

void put(int value){
    if(isFull() == 1){
        size = size + 10;
        arr = realloc(arr, sizeof(int)*size);
    }

    if(countElement == 0){
        int index = hashkey(value);
        arr[index] = value;
        countElement++;
    }else{
        int index = hashkey(value);
        while(arr[index] != __INT_MAX__){
            if(index%size == 0){
                index = 0;
            }
            index++;
        }
        arr[index] = value;
        countElement++;
    }
}

int hashkey(int value){
    return value%size;
}

int isFull(){
    int count = 0;
    for (size_t i = 0; i < size; i++){
        if(arr[i] != __INT_MAX__)count++;
    }
    if(count == size){
        return 1;
    }else{
        return 0;
    }
}

void print(){
    for (size_t i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
    
}