#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
	char *bin_num;
	int len,i;
	double dec_num;
	
	bin_num=(char *)malloc(40*sizeof(char));
	cin>>bin_num;
	
	len = (strlen(bin_num)-1);
	
	dec_num = 0;
	
	for(i=len;i>=0;i--)
		if(bin_num[i]=='1')
			dec_num+=pow(2.0,(double)(len-i));
		
	cout<<dec_num<<"\n";
	
	return 0;
}
