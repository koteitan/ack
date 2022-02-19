#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LENMAX (65536)
static void print_array(int d[], int len);
static void print_help(void);
int main(int argc, char **argv){
  const int lenmax = LENMAX;
  if(argc==1){
    print_help();
    return EXIT_SUCCESS;
  }
  /* input */
  int len=argc-1;
  if(len>lenmax) len=lenmax;
  int d[lenmax]; 
  for(int i=0;i<len;i++){
    d[i]=atoi(argv[i+1]);
  }
  
  while(len>1){
#if 1
    print_array(d, len);
    printf("\n");
#endif
    int m = d[len-2];
    int c = d[len-1];
    if(m>0){
      if(c>0){
        /* walking */
        d[len-2] = m-1; /* mother leaves track */
        d[len-1] = m;   /* mother */
        d[len]   = c-1; /* child spends */
        len++;
      }else{
        /* mother give */
        d[len-2]--; /* mother gives */
        d[len-1]++; /* child receives */
      }
    }else{
      /* zero eater */
      d[len-2] = c+1; /* child eats mother */
      len--;
    }

    if(len>=lenmax-1){
      printf("docter stop.\n");
      break;
    }
  }
  print_array(d, len);
  printf("\n");
  return EXIT_SUCCESS;
}
static void print_array(int d[], int len){
  /* output */
  printf("[");
  for(int i=0;i<len;i++){
    printf("%d",d[i]);
    if(i<len-1){
      printf(",");
    }
  }
  printf("]");
}
static void print_help(void){
  printf("Usage: ack [a0] [a1] ...\n");
  printf("ack calculates A(a0,A(a1, ... A(ak-1, ak)))...) step by step until the value is calculated as a natural number.\n");
  printf("A(x,y) is the Péter's Ackermann function [1]. Which can be represented as the followings:\n");
  printf("  A(0  ,y  ) = y+1           (for all y)\n");
  printf("  A(x+1,0  ) = A(x,1)        (for all x>0)\n");
  printf("  A(x+1,y+1) = A(x,A(x+1,y)) (for all x>0 and y>0)\n");
  printf("References:\n");
  printf("  [1] Péter, R. Rekursive Funktionen in der Komputer-Theorie. Budapest: Akad. Kiado, 1951.\n");
}
