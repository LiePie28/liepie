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
   int code = 0 ;
   int cut = 0 ;
   
   
   //unsigned long long FIB( int N ){
	   //if(N==0)
	//	 return 1;
	//   else if(N==1)
	//	 return 1;
	//   else
	//	 return FIB(N-1) + FIB(N-2) ;
    // }
    printf( "請輸入指令\n  0 : 退出\n  1 : 迴圈\n  2 : 遞迴\n")  ;
    scanf("%d", &loop );
  
  
    while( loop != 0 ){

      if(loop == 1){
        printf("請輸入你想要數字\n") ; 
        scanf("%d", &N );
        while( time1 < N ){
   	      if(num == 0) {
		    num = first  ;
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
	   time1 = 0 ;
	   num = 0 ;
	   tem = 1;
	   tem2 = 0 ;
	   printf( "請輸入指令\n  0 : 退出\n  1 : 迴圈\n  2 : 遞迴\n")  ;
       scanf("%d", &loop );
     }
     if(loop == 2){
       //FIB(N) ;
     }
     else if (loop != 1 && loop != 2 && loop != 0 ){
     	printf( "error code Please try again!!\n") ;
   	  scanf("%d", &loop );
     }
   
    }
	return 0;
}



