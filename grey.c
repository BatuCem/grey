#include <stdio.h>
#include <math.h>
#define BITS 6
int printbin(int N)
{
	int cont = 1<<(BITS-1); // The control number will start from 1000.... where 1 is the msb and BITS-1 bits away from the 1st bit, this enables us to focus on the bits of our initial number from the msb to lsb
	for(int i=BITS-1;i>=0;i--) // The increments make sure that we loop only enough times and helps us 
	{
		printf("%d",(N&cont)>>i); // The bitwise and will find if the bit we are focusing on is 1 or 0 by: N= 100111 & cont = 100000 => i=5 => (N&cont)>>i = 1 or N=10 & cont=01 => i=0 => (N&cont)>>i = 0  
		cont = cont>>1; //The control number will incrementally descend as 1000... 0100... 0010... 0001... so that we sweep every bit of our inital number N
	}
	//puts(""); //Optional newline
	
}

int generate_grey(int num)
{
	return num^(num>>1); // in order to generate grey code from a binary binary number, we must sum the binary number with itself, only one bit shifted to right and don't count the carries which is actually bitwise XOR operation.
}

int main()
{
	for(int i=0;i<pow(2,BITS);i++) //represent all the numbers in specified bit amount
	{
		printf("Bin: ");
		printbin(i);
		printf("\tGrey: ");
		printbin(generate_grey(i));
		puts("");
	}
}
