#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	unsigned long int i,mod,m,fib_tmp1,fib_tmp2,fib_number,n;
	//long double       ;
	
	cin>>n;
	cin>>m;
	
	fib_tmp1 = 0;
	fib_tmp2 = 1;
	i=2;
	
	while(i<=n) {
		fib_number = ((fib_tmp1+fib_tmp2)%m);
		fib_tmp1 = (fib_tmp2%m);
		fib_tmp2 = (fib_number%m);
		i++;
	}
	
	cout<<fib_number;
	
	return 0;
}

