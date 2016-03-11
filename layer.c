#include"fun.h"

double *_G(int n,double*dest,double tau,double h,double *v,double *hat_v){
  int m;
  for (m=2;m<n-2;m++) //схема такая, что крайние две точки с каждой стороны не считаются
    dest[m-2] = -(	(  hat_v[m] - v[m]  ) / tau + 
		( (hat_v[m+1])*(hat_v[m+1]) - (hat_v[m-1])*(hat_v[m-1]) )/(4*h) -
		omega/8.*(v[m+2] -4*v[m+1] + 6*v[m] - 4*v[m-1] + v[m-2]));
  return dest;
}

double norm_max(int n,double *v){
  int i; double max=0;
  for (i=2;i<n-2;i++) max = fmax(max,fabs(v[i]));
  return max;
}

//Пусть эта штука будет рекурсивно себя вызывать и возвращать число итераций
int layer(double eps,int n,double tau,double h,double *v,double *hat_v){
  double err,gamma,*a,*c,*d,*b,*w,*pts[5]; int i;
  new_double(5,n,pts);
  a = pts[0];  c = pts[1];  d = pts[2];  b = pts[3]; w = pts[4];
  _G(n,b,tau,h,v,hat_v);
  err = norm_max(n,b);
  if (err<eps) printf("Ошибка %e\neps %e\n",norm_max(n,b),eps);
  if (norm_max(n,b) < eps) {
    clean_all(4,pts); return 0;
  }
  for(i=n-6,a[n-5] = 1/tau;i>=0;i--) {
    a[i] = 1/tau;
    c[i] = hat_v[i+3]/(2*h); d[i] = -hat_v[i+2]/(2*h);
  }
  thomas(n-4,w+2,a,c,d,b); for (gamma=1.;gamma>AESH_MIN;gamma/=2.){
     if (gamma<10*AESH_MIN) exit(-1);
    for (i=2;i<n-2;i++) hat_v[i] += gamma * w[i];
    _G(n,b,tau,h,v,hat_v); printf("Ошибка %e\n",norm_max(n,b)); if (norm_max(n,b)<err) break;
    for (i=2;i<n-2;i++) hat_v[i] -= gamma * w[i];
  }
  clean_all(5,pts);
  return 1 + layer(eps,n,tau,h,v,hat_v);
}
