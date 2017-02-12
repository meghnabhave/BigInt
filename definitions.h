#ifndef DEF
#define DEF

#define BASE 100000000000000000


//to define sign of the bigint
typedef enum{negative,positive} SIGN;

//each digit of a bigint is said to be 17 digits of a integer. base 10^17
typedef struct digit9_tag{
	unsigned long long int d;
	struct digit9_tag *next;
} digit9;

//wrapping number and sign. number is a linked list with least significant bit at the head
typedef struct bigInt_tag{
	digit9 *number;
	SIGN s;
} bigInt;

#endif
