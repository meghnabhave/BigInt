#include"iodata.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"definitions.h"

#include"helper.h"


//to enter the string of numbers.
char* enter()
{	
	char *number;
	number=(char*)malloc(300);
	printf("Enter your big integer: ");	
	scanf("%s",number);

	return(number);
}



//to fill the linked list bigint->number
bigInt enterbigint()
{
	bigInt b;
	b.number=NULL;
	digit9 *nptr;
	char *number,*num;
	number = enter();  //enter whole number at once
	
	int i=0,j=0;
	int length = strlen(number);
	if(number[0]=='-')
	{
		i=1;
		length--;
		b.s=negative;
	}
	else
	{
		b.s=positive;
	}
	if(number[0]=='+')
	{
		i=1;
		length--;
	}
	int n2=length%17; //no of digits in msb
	
	if(n2 == 0)
	n2=17;
	
	unsigned long long int n;
	num=(char*)malloc(17);
	while(j<n2)
	{
		num[j]=number[i];
		j++; i++;
	}
	n=ctoi(num,n2);
	nptr=makenode(n);
	nptr->next=b.number;
	b.number=nptr;
	while(i<length)
	{
		j=0;	
		while(j<17)
		{
			num[j]=number[i];
			j++; i++;
		}
		n=ctoi(num,17);
		nptr=makenode(n);
		nptr->next=b.number;
		b.number=nptr;
		
	}
	free(number);
	free(num);
	b=rearrange(b);
	return(b);
		
}


//displays bigint
void display(digit9 *num)
{
	if(num!=NULL)
	{
		display(num->next);
		printf("%lld",num->d);
	}	
	
} 

//displays bigint, uses display
void printbigint(bigInt b)
{
	b=rearrange(b);
	if(b.s == negative && b.number != NULL)
	printf("-");
	if(b.number != NULL)
	display(b.number);
	else
	printf("0");

}


