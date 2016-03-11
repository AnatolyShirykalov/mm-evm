#include "fun.h"

int pl(int n,double *v){
  int i;
  for(i=0;i<n;i++) printf("%e ",v[i]); printf("\n");
}

int main(int argc,char**argv){
  int N,M,i; double tau,h,eps,*v,*hat_v,*pts[2];
  if (argc<4) {printf("%s 1/tau 1/h eps\n",argv[0]); return 0;}
  N = atoi(argv[1]); M = atoi(argv[2]);  eps = atof(argv[3]);
  h = 1./M;  tau = 1./N;
  new_double(2,N,pts); v = pts[0]; hat_v = pts[1];
    v0(N,v);
//    pl(N,v);
    v_bounds(N,1/M,hat_v);
    for (i=2;i<N-2;i++) hat_v[i] = v[i];
    layer(eps,N,tau,h,v,hat_v);
    pl(N,hat_v);
  clean_all(2,pts);
  return 0;
}
