//Quicksort en un hilo
// se compila así­:
// gcc QS.c -o QS
// se ejecuta: ./QS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
   
void swap(long *x,long *y) 
{
   long temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
   
long choose_pivot(long i,long j )
{
   return((i+j) / 2);
}
   
void quicksort(long vector[],long m,long n)
{
   long key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&vector[m],&vector[k]);
      key = vector[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (vector[i] <= key))
                i++;
         while((j >= m) && (vector[j] > key))
                j--;
         if( i < j)
              swap(&vector[i],&vector[j]);
      }
      // intercambia dos elementos
      swap(&vector[m],&vector[j]);
      // Ordena recursivamente ambas vectoras
      quicksort(vector,m,j-1);
      quicksort(vector,j+1,n);
   }
}

void printvector(long vector[],long n)
{
   long i;
   for(i=0;i<n;i++)
      printf("%d %d\n", i, vector[i]);
}

double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}
 
void main(void)
{
   const long MAX_ELEMENTS = 1000; //Tamaño del vector
//   long vector[MAX_ELEMENTS];
   long *vector = malloc(MAX_ELEMENTS * sizeof(long));

   struct timeval t_ini, t_fin;
   double secs;
   long i = 0;
 
   // genera los números aleatorios para llenar el vector
   unsigned long iseed = (unsigned long)time(NULL);
   srand (iseed);
   for(i = 0; i < MAX_ELEMENTS; i++ ){
       vector[i] = rand() % 999999999999; //Números grandes (12 dígitos)
   }

//   printf("\nMuestra el vector antes de ordenarse:\n");
//   printvector(vector,MAX_ELEMENTS);
     
   // ordena el vector usando el quicksort
   gettimeofday(&t_ini, NULL);

   quicksort(vector,0,MAX_ELEMENTS-1);

   gettimeofday(&t_fin, NULL);
   secs = timeval_diff(&t_fin, &t_ini);
   printf("%.4g milliseconds\n", secs * 1000.0);

   // Muestra el resultado
   printf("\nvectora ordenada:\n");
//   printvector(vector,MAX_ELEMENTS);
}
