//Candidate Name: Thomas Gascoyne
//Candidate Number: 201419827
//Email: T.D.Gascoyne@student.liverpool.ac.uk

#include <stdio.h>
#include <stdlib.h>

//C code
int main(void)
{
	//Declare variables in C
	char msg[] = "How many integers would you like to enter?: ";  
	int count; //The counter passed to ecx for the loop
	int num; //The integer entered by user to be evaluated
	int posCount = 0; //Keeps track of positive numbers
	int negCount = 0; //Keeps track of negative numbers
	int zeroCount = 0; //Keeps track of zero numbers
	char fmt[] = "%d"; //formats integers to decimal ints
	char prompt[] = "\nEnter an Integer: ";
	char positive[] = "\nPositive: %d";
	char negative[] = "\nNegative: %d";
	char zero[] = "\nZero: %d";

	//Assembly code
	_asm
	{
		//Prints the msg variable
		lea eax, msg; get address of msg
		push eax; push address of msg to stack
		call printf
		pop eax; restore eax

		//Accepts int user input, and stores in the count variable
		lea eax, count; get address of count
		push eax; push address of count to stack
		lea eax, fmt; get address of fmt
		push eax; push address of fmt to stack
		call scanf
		add esp, 8; clears stack

		//Checks whether count <= 0, if so, jumps to endfloop, skipping the loop
		mov eax, count; moves value of count into eax
		cmp eax, 0; compares value of eax with 0
		jz endfloop; jumps to endfloop subroutine when num = 0
		jng endfloop; jumps to endfloop subroutine when num < 0

		//Sets up for loop to loop (count) times
		mov ecx, count; move value of count to ecx 
		floop :
		//Prints the prompt variable
		push ecx
			lea eax, prompt; get address of prompt
			push eax; push address of prompt to stack
			call printf
			pop eax; restore eax

			//Accepts int user input to be stored in the num variable
			lea eax, num; get address of num
			push eax; push address of num to stack
			lea eax, fmt; get address of fmt
			push eax; push address of fmt to stack
			call scanf
			add esp, 8; clears stack

			//Compares the value of num with 0
			mov eax, num; moves value of num into eax
			cmp eax, 0; compares value of eax with 0
			jz ifzero; jumps to ifzero subroutine when num = 0
			jg ifpos; jumps to ifpos subroutine when num > 0
			jng ifneg; jumps to ifneg subroutine when num < 0

			//Increments the zeroCount counter
			ifzero:
				add zeroCount, 1
				jmp endif
			
			//Increments the negCount counter
			ifneg:
				add negCount, 1
				jmp endif
					
			//Increments the posCount counter
			ifpos:
				add posCount, 1
				jmp endif

			endif:

			pop ecx; restore ecx
			loop floop; loop back to start of floop

		endfloop: 

		//Prints positive variable plus the contents of posCount
		push posCount; push posCount to stack
		lea eax, positive; get address of positive
		push eax; push address of positive to stack
		call printf
		add esp, 8; clears stack

		//Prints negative variable plus the contents of negCount
		push negCount; push negCount to stack
		lea eax, negative; get address of negative
		push eax; push address of negative to stack
		call printf
		add esp, 8; clears stack

		//Prints zero variable plus the contents of zeroCount
		push zeroCount; push zeroCount to stack
		lea eax, zero; get address of zero
		push eax; push address of zero to stack
		call printf
		add esp, 8; clears stack

	}
	return 0;
}