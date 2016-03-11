#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define AESH_MIN 1e-15
#define omega 1.

int clean_all(int , double **);
int new_double(int,int, double **);
int thomas(int,double*,double*,double*,double*,double*);

double *_G(int,double*,double, double ,double *,double *);
double norm_max(int ,double *);
int layer(double ,int ,double ,double ,double *,double *);
double *v_bounds(int ,double ,double *);
double *v0(int ,double *);
double analitic(double ,double );
