#include "fun.h"

void pl(int n,double *v){
  int i;
  for(i=0;i<n;i++) printf("%e ",v[i]); printf("\n");
}

int main(int argc,char**argv){
  int N,M,i,j; double tau,h,eps,*v,*hat_v,*delta_v,*pts[3];
  if (argc<4) {printf("%s 1/tau 1/h eps\n",argv[0]); return 0;}
  N = atoi(argv[1]); M = atoi(argv[2]);  eps = atof(argv[3]);
  h = 1./M;  tau = 1./N;
  new_double(3,N,pts); v = pts[0]; hat_v = pts[1];  delta_v = pts[2];
    v0(N,v);
//    pl(N,v);
  for(j=0;j<M;j++){
    v_bounds(N,j/M,hat_v);
    for (i=2;i<N-2;i++) hat_v[i] = v[i];
    layer(eps,N,tau,h,v,hat_v);
    
    for (i=0;i<N;i++) delta_v[i] = fabs(analitic( ((double)j)/M ,((double)i)/N) - hat_v[i] );
    
    printf("layer %d с ошибкой %e\n",j,norm_max(N,delta_v));
    for (i=2;i<N-2;i++) v[i] = hat_v[i];
  }
  clean_all(3,pts);
  return 0;
}
