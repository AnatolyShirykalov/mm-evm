#include "fun.h"

int new_double(int n,int c,double** ptr){
  int i;
  for (i=0; i<n; i++) ptr[i] = (double*)malloc(c*sizeof(double));
  return n-i;
}

int clean_all(int n,double **ptr){
  int i;
  for (i=0; i<n; i++) if (ptr[i]!=NULL) free(ptr[i]);
  return n-i;//если не ноль, то ошибка
}
