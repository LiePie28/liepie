#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int IsPrime( unsigned long long n ) {
	if(n <= 1 ) return 0;
	if( n % 2 == 0 ) return 0 ;
	for( int i = 3 ; i <= n/i ; i += 2 ){
		if (n % i == 0 )
		  return 0 ;
	}
	return 1 ;
}

void total ( unsigned long long &num, unsigned long long &temp, unsigned long long &N, unsigned long long &time , int &cut ) {
        if ( N == 1  ) {
           num = 1 ;
           temp = 1 ;
           cut = 1 ;
           time = 1 ;         
        }
        else if( IsPrime( N ) ) {
       	  temp = N ;
       	  cut = 1 ;
       	  time = 1 ;
	    }
	    else if( (float)N / sqrt(N) == sqrt(N) && (unsigned long long )sqrt(N)*(unsigned long long )sqrt(N) == N ){ //�p�G�O��������ƪ��� 
			
			time++;                                   //����++ 
			temp = (unsigned long long)sqrt(N);   //�]�wnumber1
			cut = (unsigned long long)sqrt(N);   //�]�wnumber2
		                                    //���X�j�� 
	    }
	    else {  //�p�G���O��������ƪ��� 
	        if ( num == 1 ) {
			  num = (unsigned long long)sqrt(N) ; 
			  printf( "%llu\n", num ) ;
			} // �q����ڶ}�l���U�� 
		    time++;
			if( N % num == 0){    //�p�G�i�H�㰣 
				temp = N/num ;     //�]�w number1�����p���]�� 
	         	cut = num;  //�]�w number2�����j���]�� 
			}
			else{
				num = num - 1  ;
				printf( "%llu\n", num ) ;
	            time = time + 1 ; 
                total( num, temp, N, time, cut ) ;
			}
								
	    }
 
       
} // total()



unsigned long long f[10000] ;

unsigned long long FIB( int N  ){
	   if(N == 0) {
	     f[N] = 1 ;
		 return f[N] ;
       }   
	   else if( N == 1) {
	     f[N] = 1 ;
		 return f[N] ;
	    } 
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
   
    printf( "�п�J���O\n  0 : �h�X\n  1 : �j��\n  2 : ���j\n")  ;
    scanf("%d", &loop );
      
  
    while( loop != 0 ){

      if(loop == 1){
        printf("�п�J�A�Q�n�Ʀr\n") ; 
        scanf("%d", &N );
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
	   time1 = 1 ;
	   num = 0 ;
	   tem = 1;
	   tem2 = 0 ;
	   printf( "�п�J���O\n  0 : �h�X\n  1 : �j��\n  2 : ���j\n")  ;
       scanf("%d", &loop );
     }
     if(loop == 2){
     	
        printf("�п�J�A�Q�n�Ʀr\n") ; 
        scanf("%d", &N );
        while ( time1 <= N ){
          num = FIB( time1 ) ;
          total( number, temp, num, time, cut ) ;
          printf("[%d]%llu = %llu*%llu [Inerlooptime:%llu]\n", time1, num, cut, temp, time) ;
          number = 1 ;
          time = 0 ;
          cut = 0 ;
          temp = 0 ;
          time1 ++ ;
        } 
        
       printf( "�п�J���O\n  0 : �h�X\n  1 : �j��\n  2 : ���j\n")  ;
       scanf("%d", &loop );
       time1 = 1 ;
       num = 0 ;
       
     }
     else if (loop != 1 && loop != 2 && loop != 0 ){
     	printf( "error code Please try again!!\n") ;
   	  scanf("%d", &loop );
     }
   
    }
	return 0;
}






