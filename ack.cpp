#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
static void print_array(int d[], int len);
int main(int argc, char **argv){
  const int lenmax =1000;
  /* input */
  int len=argc-1;
  if(len>lenmax) len=lenmax;
  int d[lenmax]; 
  for(int i=0;i<len;i++){
    d[i]=atoi(argv[i+1]);
  }
  
  while(len>1){
    print_array(d, len);
    printf("\n");
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
