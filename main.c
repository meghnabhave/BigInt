#include<stdio.h>

#include"bigIntLibrary.h"

void main()
{
	printf("What's up!? \n");
	
	bigInt num1,num2;
	num1 = enterbigint();
	num2 = enterbigint();

	printbigint(num1);
	printf(" + ");
	printbigint(num2);
	printf(" = ");	
	
	bigInt result;
	result=Add(num1,num2);
	printbigint(result);
	printf("\n");

	printbigint(num1);
	printf(" X ");
	printbigint(num2);
	printf(" = ");	
	
	bigInt product;
	product=Multiplication(num1,num2);
	printbigint(product);
	printf("\n");
	
	int a=Compare(num1,num2);
	if(a==0)
	{
		printf("\nEqual\n");
	}
	else if(a==1)
	{
		printbigint(num1);
		printf(" is greater.\n");
	}
	else
	{
		printbigint(num2);
		printf(" is greater.\n");
	}
}

