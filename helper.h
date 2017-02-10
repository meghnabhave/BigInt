#ifndef HELPER
#define HELPER


#include<stdio.h>
#include"definitions.h"

unsigned long long int power(int x,int y);
digit9* makenode(unsigned long long int n);
unsigned long long int ctoi(char *num,int length);
void comprr(digit9 *num1,digit9 *num2,int *flag);
int compare(bigInt num1, bigInt num2);
bigInt rearrange(bigInt num);
int Compare(bigInt num1, bigInt num2);

#endif
