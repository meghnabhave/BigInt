#include"addfunctions.h"

#include<stdio.h>
#include<stdlib.h>

#include"helper.h"
#include"definitions.h"


//adds given bigInts
bigInt Add(bigInt b, bigInt n)
{
	//b=rearrange(b);
	//n=rearrange(n);
	bigInt result;
	if(b.number == NULL)
	result=n;
	else if(n.number == NULL)
	result=b;
	else if(n.s == b.s)
	{
		result.number=makenode(0); //dummy node
		digit9 *p1,*p2,*nptr,*tail;
		tail = result.number;
		long long int add,carry=0;
		p1=b.number;
		p2=n.number;
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
		if(carry!=0)
		{
			nptr=makenode(carry);
			tail->next=nptr;
			tail=nptr;
		}	
		tail->next = NULL;
	
		nptr = result.number;
		result.number = result.number->next;
		free(nptr);

		result.s=n.s ;	
	}
	else  //for subtraction
	{
		digit9 *large, *small;	
		int cmpr=compare(b,n);
		if(cmpr == 0)
		{
			result.number=NULL;
			result.s=positive;
		}
		else if(cmpr>0)
		{
			result.s=positive;
			large=b.number;
			small=n.number;
		}
		else
		{
			result.s=negative;
			large=n.number;
			small=b.number;
		}
		if(cmpr!=0)
		{
			digit9 *tail,*nptr;
			int diff;
			result.number=makenode(0); //dummy node
			tail=result.number;
			while(large && small)
			{
				if(large->d >= small->d)
				{
					diff=large->d - small->d;
					nptr=makenode(diff);
					tail->next=nptr;
					tail=nptr;
				}
				else
				{
					(large->next)->d=(large->next)->d-1;
					large->d = large->d + BASE;
					diff=large->d - small->d;
					nptr=makenode(diff);
					tail->next=nptr;
					tail=nptr;
				}
				large=large->next;
				small=small->next;
			}
			while(large)
			{
				nptr=makenode(large->d);
				tail->next=nptr;
				tail=nptr;
				large=large->next;
			}
			nptr=result.number;
			result.number=(result.number)->next;
			free(nptr);
		}
			
			
	} 
	return(result);	
}

