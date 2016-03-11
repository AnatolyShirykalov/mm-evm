#include "fun.h"

double analitic(double t,double x){
  if (x<AESH_MIN) return 0.;
  if (x-t>0.25) return 1.;
  return 4*x/(1+4*t);
}

double *v0(int n,double *v){
  int i;
  for(i=0;i<n;i++) v[i] = analitic(0,((double)i)/n);
  return v;
}

double *v_bounds(int n,double t,double *v){
  v[0] = analitic(t,0);
  v[1] = analitic(t,1./n);
  v[n-2] = analitic(t,1-2./n);
  v[n-1] = analitic(t,1-1./n);
  return v;
}
