#include <stdio.h>
#include <stdlib.h>
int get_valid_number();
bool is_prime(int x)

//main() uses a sentinel controlled loop to test the primality of numbers
//, without knowing how many numbers to be tested.
// -1 is the sentinel value
// the loop repeats the cycle of read->test->process->read ...
int main()
{
	int n;
        n = get_valid_number(); //read
	while (n!=-1) { //test
		//process
		if (is_prime(n)) {
			printf("%d is a prime number!\n", n);
		}
		else {
			printf("%d is not a prime number!\n", n);
		}
		int n;
		//read again then loop back to test
		n = get_valid_number();
	}
	return 0;
}

bool is_prime(int n) {
	//if n is divisible by any number greater or equal to 2 and less than n, then n is not prime.
	for (int i = 2; i < n; i++) {
		if (n%i == 0) {
			break;
		}
	}
	return !(n%i==0);
}

int get_valid_number(void) {
	//The valid number is either -1 (to exit the program) or an integer greater than 2.
	//A loop is used to implement input validation, that is, user will be asked to 
	//enter a valid number over and over again until a valid number is received.
        int n;
	printf("Please enter an integer greater than 2 to test its primality, enter -1 to exit \n");
	scanf("%d", &n);
	while (n <= 2 || n != -1) {
		printf("Please enter an integer greater than 2 to test its primality, enter -1 to exit \n");
		scanf("%d", &n);
	}
	return n;
}
