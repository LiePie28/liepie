#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

   unsigned long long number = 1;
   unsigned long long time = 0;
   unsigned long long temp = 0;
   int N = 92;
   unsigned long long num = 0 ;
   int first = 1 ;
   unsigned long long tem = 1 ;
   unsigned long long tem2 = 0 ;
   int time1 = 0 ;
   int loop = 1 ;
   int cut = 0 ;
   bool yes = true;
   
   //unsigned long long FIB( int N ){
	   //if(N==0)
	//	 return 1;
	//   else if(N==1)
	//	 return 1;
	//   else
	//	 return FIB(N-1) + FIB(N-2) ;
  // }
   
    if(loop == 1){
   
	 while( time1 < N ){
   
   	    if(num == 0) {
		  num = first + 0 ;
		  time1 ++ ;
	    }

	   
	    else{
		 tem2 = num ;
		 num = num + tem ;
		 tem = tem2 ;
		 time1 ++;
	    }
	
	    while( number * number <= num  ) {
	     if ( num % number == 0){
		   temp = num/number ;
		   cut = number ;
	     } 
	      if ( temp == 1 )
	        time ++ ;
	     
	      if( number*number < temp )
            time ++ ;
          number++ ;

          
	   }   
	   printf("[%d]%llu = %llu*%llu [Inerlooptime:%llu]\n", time1, num, cut, temp, time) ;
	   temp = 0 ;
	   number = 1 ;
	   time = 0 ;
	   cut = 0 ;

	 }
   
   }
   if(loop == 2){
       //FIB(N) ;
   }
	return 0;
}



