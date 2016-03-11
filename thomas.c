#include"fun.h"

int thomas(int n,double *dest,double*a,double*c,double*d,double *b){
  double *l,*v,*u,*pts[3]; int i;
  if (n<2) return n-2;
 // for (i=0;i<n-5;i++) printf("%e %e %e %e\n",a[i],c[i],d[i],b[i]);
  new_double(3,n,pts);
  l = pts[0]; v = pts[1], u = pts[2];
  // Богачёв первый этап прогонки
//  printf("d0 = %e\n",d[0]);
  v[0]=d[0]; if (fabs(v[0])<AESH_MIN) {printf("d[0] zero delimeter\n"); clean_all(3,pts); exit(-1);}
  l[0] = a[0]/v[0];if (fabs(l[0])<AESH_MIN) {printf("l[0] zero delimeter %e/%e = %e\n",a[0],v[0],l[0]); clean_all(3,pts);exit(-1);}
  u[0] = c[0]/l[0];
  for (i=1;i<n-1;i++) {
    v[i] = d[i]; if (fabs(v[i])<AESH_MIN) {printf("v[%d] zero delimeter\n",i); exit(-1);}
    l[i] = (a[i] - u[i-1])/v[i];if (fabs(l[i])<AESH_MIN) {printf("l[%d] zero delimeter\n",i); clean_all(3,pts); exit(-1);}
    u[i] = c[i]/l[i];
  }
  l[n-1]=a[n-1]-u[n-2];
  v[n-1]=1;
  // Богачёв замечание 4
  for(i=1,dest[0]=b[0]/l[0]; i<n; i++) dest[i] = (b[i]-dest[i-1])/l[i];
  for(i=n-2;i>=0; i--) dest[i] = (dest[i] - u[i]*dest[i+1])/v[i];
  clean_all(3,pts);
  return 0; 
}
