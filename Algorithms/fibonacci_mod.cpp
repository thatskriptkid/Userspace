#include <iostream>
#include <math.h>

using namespace std;

void fib_matrix_multiplication(int fib_number)
{
	unsigned long int  matrix_A[2][2]={0};
	unsigned long int				   matrix_base[2][2] = {{1,1},{1,0}};
	unsigned long int				   matrix_tmp[2][2] = {{1,1},{1,0}};
	int i,j,k,g;
	
	for(g=0;g<10;g++) {
	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			for(k=0;k<2;k++) {
				matrix_A[i][j] += matrix_tmp[i][k] * matrix_base[k][j];
			} 
					
		} 
	}
	
	for(i=0;i<2;i++) {
			for(j=0;j<2;j++)
				cout<<matrix_A[i][j]<<"\t";
			
			cout<<"\n";
	}
	cout<<"\n";
	for(i=0;i<2;i++) 
		for(j=0;j<2;j++)
					matrix_tmp[i][j]=matrix_A[i][j];
					
	}
	
	//return matrix_A[0][0];
}

int main(int argc, char **argv)
{
	fib_matrix_multiplication(4);
		
	return 0;
}

