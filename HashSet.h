#include<stdlib.h>
#include<stdio.h>

int size = 10;
int *arr;
int countElement = 0;

void put(int value);
int hashkey(int value);
int isFull();
void print();
void initialize();
int removeEle(int value);