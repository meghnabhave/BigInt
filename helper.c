
#include<stdio.h>
#include<stdlib.h>
#include"helper.h"
//finds x to power y
unsigned long long int power(int x,int y)
{
	unsigned long long int i,pow=1;
	for(i=0;i<y;i++)
	pow=pow*x;
	
	return(pow);
}

//abstracting out the function for making a node
digit9* makenode(unsigned long long int n)
{
	digit9 *nptr;
	nptr=(digit9*)malloc(sizeof(digit9));
	nptr->d=n;
	nptr->next=NULL;
	return(nptr);
}

//converts character string to numbers
unsigned long long int ctoi(char *num,int length)
{
	unsigned long long int p = power(10,length-1);
	unsigned long long int number=0,i=0;
	while(p >= 1)
	{
		number=number+ ((num[i]-'0')*p);
		i++;
		p=p/10;
	}
	return(number);
}

//recursive function to print from MSB(last node of linked list) to LSB(first node of linked list
void comprr(digit9 *num1,digit9 *num2,int *flag)
{
	if(*flag==0 && num1!=NULL && num2!=NULL)
	{
		
		comprr(num1->next,num2->next,flag);
		if(*flag==0)
		{
			if(num1->d > num2->d)
			*flag=1;
			else if(num1->d < num2->d)
			*flag=-1;
		}		
	}
}

//compares num1 and num2 (only magnitudes)
int compare(bigInt num1, bigInt num2)
{
	int flag=0;
	comprr(num1.number,num2.number,&flag);
	return(flag);
}

//compares num1 and num2 (signed values too)
int Compare(bigInt num1, bigInt num2)
{
	int flag;
	if(num1.s==num2.s)
	{
		flag=0;
		comprr(num1.number,num2.number,&flag);	
		if(num1.s == negative)
		{
			flag=-flag;
		}
		
	}
	else if(num1.s == positive && num2.s == negative)
	{
		flag=1;
	}
	else
	{
		flag=-1;
	}
	return(flag);
}

//This function deletes nodes having zero preceding the number. Called before printing the bigInt.
void rearrange(bigInt num)
{
	if(num.number!=NULL)
	{
	
		digit9 *nptr,*lptr,*prev;
		lptr=num.number;
		nptr=lptr;
		prev=NULL;
		while(nptr->next!=NULL)
		{
			prev=nptr;
			nptr=nptr->next;
		}
		if(prev==NULL && nptr->d == 0)
		{
			free(nptr);
			num.number=NULL;
		}
		if(nptr->d == 0)
		{
			prev->next=nptr->next;
			free(nptr);
		}
	}
}
