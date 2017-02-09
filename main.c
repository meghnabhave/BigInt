#include<stdio.h>

#include"definitions.h"
#include"helper.h"
#include"iodata.h"
#include"addfunctions.h"
#include"multfunctions.h"

void main()
{
	printf("What's up!? \n");
	//printf("int :%d long:%d long long: %d\n",sizeof(int),sizeof(long),sizeof(long long));
	
	bigInt num1,num2;
	num1 = enterbigint();
	num2 = enterbigint();

	printbigint(num1);
	printf(" + ");
	printbigint(num2);
	printf(" = ");	
	
	bigInt result;
	result=add(&num1,&num2);
	printbigint(result);
	printf("\n");

	printbigint(num1);
	printf(" X ");
	printbigint(num2);
	printf(" = ");	
	
	
	/*bigInt product1;
	product1=NodexNode(num1.number,num2.number);
	printbigint(product1);
	printf("\n");*/
	
	bigInt product;
	product=Multiplication(num1,num2);
	printbigint(product);
	printf("\n");

	/**if(compare(num1,num2)==0)
	{
		printf("\nEqual\n");
	}
	else if(compare(num1,num2)==1)
	{
		printbigint(num1);
		printf(" is greater.\n");
	}
	else
	{
		printbigint(num2);
		printf(" is greater.\n");
	}*/
}
