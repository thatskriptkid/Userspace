#include <stdio.h>

unsigned long long	i,j;
unsigned long long  matrix_A[2][2]={{1,1},{1,0}},
     
					matrix_base[2][2] = {{1,1},{1,0}},
                       
					matrix_tmp[2][2] = {{1,1},{1,0}},
                       
					matrix_res_tmp[2][2]={{1,0},{0,1}},
                       
					matrix_res[2][2];

void zero_array(unsigned long long arr[][2])
{
	for(i=0;i<2;i++) 
		for(j=0;j<2;j++) 
			arr[i][j]=0;  
			
	
}

void matrix_multiplication(unsigned long long matrix_res[][2],unsigned long long matrix_left[][2],unsigned long long matrix_right[][2],unsigned long long mod)
{
    short i,j,k;
     
    for(i=0;i<2;i++) 
      for(j=0;j<2;j++) 
        for(k=0;k<2;k++) 
          matrix_res[i][j] = (((matrix_res[i][j]%mod) +((matrix_left[i][k]%mod) * (matrix_right[k][j]%mod)))%mod); 
                  
    for(i=0;i<2;i++)
           for(j=0;j<2;j++)
                 matrix_left[i][j]=(matrix_res[i][j]%mod);
}

unsigned long long  fib_matrix(unsigned long long degree,unsigned long long mod)
{
   while(degree) {
                
     if(degree&1) {  
           zero_array(matrix_res);
             
           matrix_multiplication(matrix_res,matrix_res_tmp,matrix_A,mod);
                  
        }         
     
           memset(matrix_A,0,sizeof(unsigned long long)*4);
           
           matrix_multiplication(matrix_A,matrix_tmp,matrix_tmp,mod);       
    
           degree>>=1;
      
     }
     
     return matrix_res[0][1];  
 
}
int main(int argc, char **argv)
{
    unsigned long long n ;
    unsigned long long m ;
    
    scanf("%ull",n);
    scanf("%ull",m);
    
    printf("%ull",fib_matrix(n,m);
    
    return 0;
}
