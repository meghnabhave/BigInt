# BigInt 
This is an implementation of big integers (size more than long or long long).
It can store arbitrary size of integers. 
Uses linked list, and a base 10^17 number system. 

The big integer is divided into different smaller parts each having 17 digits,starting from the LSB.
I chose the number 17 because the maximum value that a 64 bit unsigned integer can hold is 2^64-1, which is a 20 digit number. Choosing 17 digits instead of 20 optimises on space and gives wiggle room to perform multiplication operations.

Each node of the linked list is viewed as a digit of the assumed number system. Below is the structure of linked list of numbers. 

typedef struct digit9_tag{
	unsigned long long int d;
	struct digit9_tag *next;
} digit9;

Another structure, called bigInt, stores the actual number. It has a linked list of digit9's and a flag to indicate positive or negative value.
The linked list stores the digit in reverse order, ie, number->LSB->..->MSB->NULL

Functions available to the user: 

enterbigint() -> a function to take input from user. Available in bigIntLibrary.h. The input is internally taken as a character array, which is parsed and the values are stored in a bigInt structure type variable and returned to the calling function.

printbigint(bigInt b) -> a function to print the bigInt passed as parameter in appropriate format. Available in bigIntLibrary.h. The function internally calls display() which is a recursive function to print the numbers from MSB to LSB. 

Add(bigInt num1, bigInt num2) -> a funtion to add the num1 and num2, bigInts passed as parameters, and return the sum. Available in bigIntLibrary.h. The function adds each digit9 (node) of the linked list, and stores the carry of the result in a variable, and result of the addition in another linked list. Subttraction is also implemented by supplying negative sign of one of the operands. The resultant linked list is returned to the calling function.

Multiplication(bigInt num1, bigInt num2) -> a function to multiply num1 and num2, bigInts passed as parameters to the function. Available in bigIntLibrary.h. The functions calls a function NodexBigInt() which in turn calls NodexNode() which in turn calls enterformult(). The result of the multiplication is returned as a bigInt by the function. 

Compare(bigInt num1, bigInt num2) -> a function to compare num1 and num2. Available in bigIntLibrary.h. The function returns
              0 if num1 == num2
             -1 if num1<num2
              1 if num1>num2
              
              
This is it for the explanation of this project. Please suggest changes or improvements if any. Constructive criticism is always welcome.
              
              

