#ifndef MULT
#define MULT

#include<stdio.h>
#include "definitions.h"
#include "addfunctions.h"


bigInt enterformult(unsigned long long int res,int pow);
bigInt NodexNode(digit9 *num1, digit9 *num2);
bigInt Multiplication(bigInt num1, bigInt num2);
bigInt NodexBigInt(digit9 *num1,bigInt num2);

#endif
