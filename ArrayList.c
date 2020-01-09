#include<stdio.h>
#include<stdlib.h>

size_t globalsize = 0; //To keep track of items present in an array
int ind = 0; //Index at which the item need to be added or removed

//add an item
void addItem(int ** array, int value, int *size){
	if(globalsize == *size){
		// printf("globalSize: %zu Size: %d\n", globalsize, *size);
		*size = *size+1;
		*array = realloc(*array, *size * sizeof(int));
		(*array)[ind] = value;
		globalsize = globalsize + 1;
		ind = ind +1;
	}else{
		(*array)[ind] = value;
		globalsize = globalsize + 1;
		ind = ind + 1;
	}
}


//Remove the last item
int removeItem(int **array, int *size){
	int temp = (*array)[*size - 1];
	int check = *size;
	*size = *size - 1;
	globalsize = globalsize - 1;
	ind = ind - 1;
	
	int *newarray = (int *)calloc(*size, sizeof(int));

	for (size_t i = 0; i < *size; i++){
		newarray[i]=(*array)[i];
	}

	// for (size_t i = 0; i < check; i++){
	// 	free(array[i]);
	// }
	
	free(*array);
	
	(*array) = (int *)realloc(newarray, *size * sizeof(int));
	
	return temp;
}

//Insertion Sort
void sort(int **array, int size){
	for (size_t i = 0; i < size; i++){
		for (size_t j = i; j < size; j++){
			if((*array)[j] < (*array)[i]){
				int temp = (*array)[i];
				(*array)[i] = (*array)[j];
				(*array)[j] = temp;
			}
		}
		
	}
	
}

int main(){
	int size = 5;
	int *array = (int *)calloc(size, sizeof(int));
	addItem(&array, 10, &size);
	addItem(&array, 5, &size);
	addItem(&array, 50,&size);
	addItem(&array, 90, &size);
	addItem(&array, 25, &size);
	addItem(&array, 20, &size);
	addItem(&array, 60, &size);
	addItem(&array, 15, &size);
	addItem(&array, 70, &size);
	addItem(&array, 100, &size);  

	for (size_t q = 0; q < size; q++){
		printf("%d ", array[q]);
	}
	printf("\n");
	printf("Item removed: %d\n",removeItem(&array, &size));

	addItem(&array, 110, &size);

	for (size_t q = 0; q < size; q++){
		printf("%d ", array[q]);
	}
	printf("\n");
	sort(&array, size);
	printf("Sort\n");
   
	for (size_t q = 0; q < size; q++){
		printf("%d ", array[q]);
	}
	printf("\n");
	return 0;
}