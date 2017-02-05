#include<stdio.h>
#include<stdlib.h>
#define BASE 1000000000

typedef enum{negative,positive} SIGN;

typedef struct digit9_tag{
	int d;
	struct digit9_tag *next;
} digit9;

typedef struct bigInt_tag{
	digit9 *number;
	SIGN s;
} bigInt;

digit9* makenode(int n)
{
	digit9 *nptr;
	nptr=(digit9*)malloc(sizeof(digit9));
	nptr->d=n;
	nptr->next=NULL;
	return(nptr);
}

bigInt enterbigint()
{
	bigInt b;
		int n;
	b.number=NULL;
	digit9 *nptr;
	printf("Enter sign of the number: 0 for negative, 1 for positive\n");
	scanf("%d",&n);
	if(n==0) b.s=negative;
	else b.s=positive;
	
	printf("Enter 9 digits and press enter: \n Press negative number if done with numbers.");
	
	scanf("%d",&n);
	while(n>=0)	
	{
		nptr=makenode(n);
		nptr->next=b.number;
		b.number=nptr;
		scanf("%d",&n);
	}
	return(b);
}

//adds both negative or both positive numbers

bigInt add(bigInt *b, bigInt *n)
{
	bigInt result;
	if(b->number == NULL)
	result=*n;
	else if(n->number == NULL)
	result=*b;
	else if(n->s == b->s)
	{
		result.number=makenode(0); //dummy node
		digit9 *p1,*p2,*nptr,*tail;
		tail = result.number;
		int add,carry=0;
		p1=b->number;
		p2=n->number;
		while(p1 && p2)
		{
			add=p1->d + p2->d + carry;
			carry = add/BASE;
			add = add%BASE;	
			nptr=makenode(add);
			tail->next=nptr;
			tail=nptr;
			p1=p1->next;
			p2=p2->next;
		}
		
		while(p1)
		{
			add=p1->d + carry;
			carry = add/BASE;
			add = add%BASE;
			nptr=makenode(add);
			tail->next=nptr;
			tail=nptr;
			p1=p1->next;
		}

		while(p2)
		{
			add=p2->d + carry;
			carry = add/BASE;
			add = add%BASE;
			nptr=makenode(add);
			tail->next=nptr;
			tail=nptr;
			p2=p2->next;
		}	
		tail->next = NULL;
	
		nptr = result.number;
		result.number = result.number->next;
		free(nptr);

		result.s=n->s ;	
	} 

	return(result);
	
}

void main()
{
	printf("What's up!? \n");
}





