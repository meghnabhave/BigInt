#include"multfunctions.h"

#include<stdio.h>

#include"definitions.h"
#include"helper.h"

//stores result of multiplication of two nodes along with power in a linked list. 
bigInt enterformult(unsigned long long int res,int pow)
{
	bigInt b;
	b.number=NULL;
	b.s=positive;
	
	digit9 *nptr;
	int n;
	
	n=pow%17;
	unsigned long long int base;
	unsigned long long int entry;
	
	base=power(10,17-n);
		entry=res/base;
		res=res%base;
		nptr=makenode(entry);
		nptr->next=b.number;
		b.number=nptr;
		
	
	
	entry=res;
	entry=entry*power(10,n);
	nptr=makenode(entry);
	nptr->next=b.number;
	b.number=nptr;
	//enter zeroes;
	n=pow/17;
	while(n!=0)
	{
		nptr=makenode(0);
		nptr->next=b.number;
		b.number=nptr;
		n--;
	}
	return(b);
			
}


//multiply node with node
//n1 is node whose digits multiply with whole of n2
bigInt NodexNode(digit9 *num1, digit9 *num2)
{
	bigInt result,temp;
	unsigned long long int res;
	int pow=0;
	unsigned long long int n1=num1->d;
	unsigned long long int n2=num2->d;
	int rem=n1%10;
	result.number=NULL;
	result.s=positive;
	temp.number=makenode(0); //default value;
	temp.s=positive;
	while(n1!=0)
	{
		res=n2*rem;
		temp=enterformult(res,pow);
		result=Add(result,temp);
		n1=n1/10;
		rem=n1%10;
		pow++;

	}
	return result;
}

//multiplies a node with a bigInteger number(linked list). Calls NodexNode() function.
bigInt NodexBigInt(digit9 *num1,bigInt num2)
{
	bigInt temp,result,carry;
	int pow=0,i;
	temp.number=NULL;
	temp.s=positive;
	result.number=NULL;
	result.s=0;
	digit9 *nptr,*p;
	nptr=num2.number;
	while(nptr!=NULL)
	{
		temp=NodexNode(num1,nptr);
		for(i=0;i<pow;i++)
		{
			p=makenode(0);
			p->next=temp.number;
			temp.number=p;
		}
		result=Add(result,temp);
		
		pow++;
		nptr=nptr->next;
	}
	
	return(result);	
}


//multiplies two bigInts. Calls NodexBigInt()
bigInt Multiplication(bigInt num1, bigInt num2)
{
	//num1=rearrange(num1);
	//num2=rearrange(num2);
	bigInt result,temp;
	result.number=NULL;
	result.s=positive;
	
	if(num1.number!=NULL && num2.number!=NULL)
	{

		temp.number=NULL;
		temp.s=positive;
		
		digit9 *n2=num2.number;
		digit9 *p;
		int pow=0,i;
		
		while(n2!=NULL)
		{
			temp=NodexBigInt(n2,num1);
			for(i=0;i<pow;i++)
			{
				p=makenode(0);
				p->next=temp.number;
				temp.number=p;
			}
			result=Add(result,temp);
			pow++;
			n2=n2->next;		
		}
		
		if(num1.s == num2.s)
		result.s=positive;
		else
		result.s=negative;
	}
	return(result);
}

