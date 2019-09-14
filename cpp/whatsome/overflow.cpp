#include<stdio.h> 
#include<limits.h> 
#include<stdlib.h> 
  
int addOvf(int* result, int a, int b) 
{ 
   if( a > INT_MAX - b) 
     return -1; 
   else
   { 
     *result = a + b; 
      return 0; 
   } 
} 
int addOvf2(int* result, int a, int b) 
 { 
     *result = a + b; 
     if(a > 0 && b > 0 && *result < 0) 
         return -1; 
     if(a < 0 && b < 0 && *result > 0) 
         return -1; 
     return 0; 
 } 
  
int main() 
{ 
  int *res = (int *)malloc(sizeof(int)); 
  int x = 0x80000000; 
  int y = -1; 
  
  printf("%d", addOvf(res, x, y)); 
  printf("%d", addOvf2(res, x, y)); 
  
  printf("\n %d %d", *res, x); 
//   getchar(); 
  return 0; 
} 