#include <iostream>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <string.h>

using namespace std;

int main(void)
{
    char *end_ptr;
    char *buff; 
    int number_1,number_2,result,converted_result,dest_system,operation; 
    char *bin_num_1,*bin_num_2;
	int len,i;
	double dec_num_1,dec_num_2;
	
	bin_num_1=(char *)malloc(40*sizeof(char));
	bin_num_2=(char *)malloc(40*sizeof(char));
	
    cout<<"Vvedite sistemu schislenia\n";
    cin>>dest_system;
    
    switch(dest_system)
    {
     
     case 8:
          cin.unsetf(ios::dec);
          cin.setf(ios::oct);
          break;
     case 10:
          cin.setf(ios::dec);
          break; 
     case 16:
          cin.unsetf(ios::dec);
          cin.setf(ios::hex); 
          break;
     
   }   
    cout<<"Vvedite pervoe chislo\n";
    if (dest_system==2)
    cin>>bin_num_1;
    else
	cin>>number_1;
    
    cout<<"Vvedite vtoroe chislo\n";
    if (dest_system==2)
    cin>>bin_num_2;
    else
    cin>>number_2;
    
    cout<<"Vvedite nomer operacii. 1 - slozhenie, 2 - vichitanie\n";
    switch(dest_system)
    {
     case 8:
          cin.unsetf(ios::oct);
          break;
     case 16:
          cin.unsetf(ios::hex);
          break;
   }   
    cin.setf(ios::dec);
    cin>>operation;
    
    if(operation==1)
		{
			if(dest_system==2)
		{
			len = (strlen(bin_num_1)-1);
	        dec_num_1 = 0;
	         
			for(i=len;i>=0;i--)
				if(bin_num_1[i]=='1')
					dec_num_1+=pow(2.0,(double)(len-i));
					
		   len = (strlen(bin_num_2)-1);
	        dec_num_2 = 0;
	         
			for(i=len;i>=0;i--)
				if(bin_num_2[i]=='1')
					dec_num_2+=pow(2.0,(double)(len-i));
					
			result = (int)(dec_num_1+dec_num_2);
					
		}
	
		else 
		{
			result= number_1+number_2;
		}
    }
    
    if(operation==2)
		{
			if(dest_system==2)
		{
			len = (strlen(bin_num_1)-1);
	        dec_num_1 = 0;
	         
			for(i=len;i>=0;i--)
				if(bin_num_1[i]=='1')
					dec_num_1+=pow(2.0,(double)(len-i));
					
		   len = (strlen(bin_num_2)-1);
	        dec_num_2 = 0;
	         
			for(i=len;i>=0;i--)
				if(bin_num_2[i]=='1')
					dec_num_2+=pow(2.0,(double)(len-i));
					
			result = (int)(dec_num_1-dec_num_2);
					
		}
	
		else result = number_1 - number_2;
        
    }
    
    switch(dest_system)
    {
     case 8:
          sprintf(buff,"%o",result);
          break;
     case 10:
     case 2:
          converted_result=result;
          break; 
     case 16:
          sprintf(buff,"%x",result); 
          break;
   }    
  
    
    switch(dest_system)
   {
     case 2:
          cout<<bitset<sizeof(converted_result) * 8>(converted_result)<<"\n";
          break;
     case 8:
         converted_result=strtol(buff,&end_ptr,8); 
        
         cout.unsetf(ios::dec);
         cout.setf(ios::oct|ios::showbase);
         if(operation==1)
         cout<<"Resultat slozhenia = "<<converted_result<<"\n";
         
          if(operation==2)
         cout<<"Resultat vichitania = "<<converted_result<<"\n";
         break;
     case 10:
          cout.setf(ios::dec);
            if(operation==1)
          cout<<"Resultat slozhenia = "<<converted_result<<"\n";
            if(operation==2)
         cout<<"Resultat vichitania = "<<converted_result<<"\n";
          break; 
     case 16:
          converted_result=strtol(buff,&end_ptr,16); 
    
          cout.unsetf(ios::dec);
          cout.setf(ios::hex|ios::showbase);
            if(operation==1)
          cout<<"Resultat slozhenia = "<<converted_result<<"\n";
           if(operation==2)
         cout<<"Resultat vichitania = "<<converted_result<<"\n";
          break;
   } 
    
    return 0;
}

