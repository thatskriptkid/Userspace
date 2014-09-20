#include <iostream>

using namespace std;

/*
 * Search for the last digit of Fibonacci number
 */
 
int main(int argc, char **argv)
{
	unsigned short int fib_tmp1,fib_tmp2,fib_last_digit;
	unsigned long  int i,number;
	
	cin>>number;
	
	fib_tmp1 = 0;
	fib_tmp2 = 1;
	i=2;
	
	while(i<=number) {
		fib_last_digit = ((fib_tmp1+fib_tmp2)%10);
		fib_tmp1 = (fib_tmp2%10);
		fib_tmp2 = (fib_last_digit%10);
		i++;
	}
	
	cout<< fib_last_digit;
	
	
	return 0;
}
