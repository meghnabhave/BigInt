#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BASE 1000000000

//finds x to power y
int power(int x,int y)
{
	int i,pow=1;
	for(i=0;i<y;i++)
	pow=pow*x;
	
	return(pow);
}

//to define sign of the bigint
typedef enum{negative,positive} SIGN;

//each digit of a bigint is said to be 9 digits of a integer. base 10^9 
typedef struct digit9_tag{
	int d;
	struct digit9_tag *next;
} digit9;

//wrapping number and sign. number is a linked list with least significant bit at the head
typedef struct bigInt_tag{
	digit9 *number;
	SIGN s;
} bigInt;


//abstracting out the function for making a node
digit9* makenode(int n)
{
	digit9 *nptr;
	nptr=(digit9*)malloc(sizeof(digit9));
	nptr->d=n;
	nptr->next=NULL;
	return(nptr);
}

//to enter the string of numbers.
char* enter()
{	
	char *number;
	number=(char*)malloc(300);
	printf("Enter your big integer: ");	
	scanf("%s",number);

	return(number);
}

//converts character string to numbers
int ctoi(char *num,int length)
{
	int p = power(10,length-1);
	int number=0,i=0;
	while(p >= 1)
	{
		number=number+ ((num[i]-'0')*p);
		i++;
		p=p/10;
	}
	return(number);
}

//to fill the linked list bigint->number
bigInt enterbigint()
{
	bigInt b;
	b.number=NULL;
	digit9 *nptr;
	char* number,*num;
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
	int n2=length%9; //no of digits in msb
	
	if(n2 == 0)
	n2=9;
	
	int n;
	num=(char*)malloc(9);
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
		while(j<9)
		{
			num[j]=number[i];
			j++; i++;
		}
		n=ctoi(num,9);
		nptr=makenode(n);
		nptr->next=b.number;
		b.number=nptr;
		
	}
	free(number);
	free(num);
	return(b);
		
}

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

		result.s=n->s ;	
	}
	else  //for subtraction
	{
		digit9 *large, *small;	
		int cmpr=compare(*b,*n);
		if(cmpr == 0)
		{
			result.number=NULL;
			result.s=positive;
		}
		else if(cmpr>0)
		{
			result.s=positive;
			large=b->number;
			small=n->number;
		}
		else
		{
			result.s=negative;
			large=n->number;
			small=b->number;
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


//Multiplies b and n
bigInt Multiplication(bigInt b,bigInt n)
{
	bigInt result;
	if(b.number==NULL || n.number==NULL)
	{
		result.number=NULL;
		result.s=positive;
	}
	else
	{
		if(b.s == n.s)
		result.s=positive;
		else
		result.s=negative;	
		int cmpr;
		cmpr=compare(b,n);
		bigInt P,Q;
		if(cmpr>0)
		{
			Q=n;
			P=b;
		}
		else
		{
			Q=b;
			P=n;
		}
		P.s=Q.s=positive;
		bigInt minusone;
		minusone.s=negative;
		minusone.number=makenode(1);
		result.number=NULL;
		while(Q.number!=NULL)
		{
			result=add(&result,&P);
			Q=add(&Q,&minusone);
		}
	}
	return(result);
}


	

//displays bigint
void display(digit9 *num)
{
	if(num!=NULL)
	{
		display(num->next);
		printf("%d",num->d);
	}	
	
} 

//displays bigint, uses display
void printbigint(bigInt b)
{
	if(b.s == negative && b.number != NULL)
	printf("-");
	if(b.number != NULL)
	display(b.number);
	else
	printf("0");

}

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
	result=add(&num1,&num2);
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
