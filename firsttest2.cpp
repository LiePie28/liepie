#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int gtime = 0 ;

unsigned long long total ( unsigned long long num, unsigned long long N  ) {

       if ( N % num == 0 ){
       	    gtime++ ;
            return num ;
        }
        else {
            gtime++ ;           
            return total( num - 1 , N ) ;    
       }
       
} // total()

unsigned long long f[10000] ;

unsigned long long FIB( int N  ){
	   if(N == 0) {
	     f[N] = 1 ;
		 return f[N] ;
       }   
	   if( N == 1) {
	     f[N] = 1 ;
		 return f[N] ;
	   } 
	   if( f[N] != -1 ) 
	     return f[N] ; 
	   else {
	   	f[N] = FIB(N-1) + FIB(N-2) ;
	   	return f[N] ; 
       } 
}

int main(){

   unsigned long long number = 1;
   unsigned long long time = 0;
   unsigned long long temp = 0;
   int N = 0;
   unsigned long long num = 0 ;
   int first = 1 ;
   unsigned long long tem = 1 ;
   unsigned long long tem2 = 0 ;
   int time1 = 1 ;
   int loop = 1 ;
   int code = 0 ;
   int cut = 0 ;
   for( int i = 0 ; i <1000 ; i++ ){
   	f[i] = -1 ;
   }
   
    printf( "請輸入指令\n  0 : 退出\n  1 : 迴圈\n  2 : 遞迴\n")  ;
    scanf("%d", &loop );
    while (loop != 1 && loop != 2 && loop != 0 ){
     	printf( "error code Please try again!!\n") ;
     	printf( "請輸入指令\n  0 : 退出\n  1 : 迴圈\n  2 : 遞迴\n")  ;
     	scanf("%d", &loop );
    }
    printf("請輸入你想要數字\n") ; 
    scanf("%d", &N ); 
      
  
    while( loop != 0 ){
    	
	  while( N <= 0 ) {
	  	printf("error number, Please try again\n") ; 
        scanf("%d", &N );
	  }

      if(loop == 1){
        while( time1 < N ){
   	      if(num == 0) {
		    num = first  ;
		    
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
	         
	         if( number*number <= temp )
               time ++ ;
             number++ ;
	      }   
	      printf("[%d]%llu = %llu*%llu [Inerlooptime:%llu]\n", time1, num, cut, temp, time) ;
	      temp = 0 ;
	      number = 1 ;
	      time = 0 ;
	      cut = 0 ;
    
	   }
	   printf("< Outerlooptime %d >\n", N - 1) ;
	   time1 = 1 ;
	   num = 0 ;
	   tem = 1;
	   tem2 = 0 ;
     }
     else if(loop == 2){
     	
        while ( time1 <= N ){
          num = FIB( time1 ) ;
          number = (unsigned long long)sqrt(num) ;
          temp = total ( number, num ) ;
          cut = num / temp ;
          printf("[%d]%llu = %llu*%llu [Inerlooptime:%llu]\n", time1, num, temp, cut, gtime) ;
          time1 ++ ;
		  temp = 0 ;
		  gtime = 0 ;
		  cut = 0 ;
		  number = 1 ; 
	   }
	   printf("< Outerlooptime %d >\n", N - 1) ;
	   time1 = 1 ;
	   num = 0 ;
	   tem = 1;
	   tem2 = 0 ;

       
     }
     else if (loop != 1 && loop != 2 && loop != 0 ){
     	printf( "error code Please try again!!\n") ;
   	
     }
     printf( "請輸入指令\n  0 : 退出\n  1 : 迴圈\n  2 : 遞迴\n")  ;
     scanf("%d", &loop );
     printf("請輸入你想要數字\n") ; 
     scanf("%d", &N ); 
   
    }
	return 0;
}






