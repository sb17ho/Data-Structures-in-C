#include"HashSet.h"

int main(){
    arr = calloc(size, sizeof(int));
    initialize();
    put(2);
    put(5);
    put(3);
    put(1);
    print();
    printf("Removed: %d\n", removeEle(5));
    printf("After removal\n");
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

int removeEle(int value){
    int result = 0;
    if(arr[hashkey(value)] == value){
        int index = hashkey(value);
        result = arr[index];
        arr[index] = __INT_MAX__;
    }else{
        int i = 0;
        while(arr[i] != value){
            i++;
        }
        result = arr[i];
        arr[i] = __INT_MAX__;
    }
    return result;
}

void print(){
    for (size_t i = 0; i < size; i++){
        if(arr[i]==__INT_MAX__)printf(".\n");
        else printf("%d\n", arr[i]);
    }
    
}