#include <stdio.h>
#include <math.h>

//  KdV equation:
//  D_l(U) + D_xxx(U) + 6*U*[D_x(U)] = 0
//
//  INITAL CONDITIONS:
//  			1. D_l(U) + D_xxx(U) + 6*U*[D_x(U)] = 0 : 0 < x < inf, 0 < t < inf
// 			2. U(x,0) = U_initial : 0 < x < inf, U_initial >= 0
// 			3. U(0,t) = U_b(t) : t > 0, U_b > 0



//---------------------------------------------------------------------
// INITIAL CONDITIONS

double xmin = 0, xmax = 0.0005;

// Main

int
main(int argc, char **argv)
{
  const int N = 100; 
  int i;
  const int iterations = 100000;
  double dx = (xmax - xmin)/N; 
  double U[N];
  for (i = 0; i < N; i++) {
    U[i] = sin(i*dx); //Make the original guess function periodic
  //printf("%lf\n", array[i]);
  }  
  
  for (int j = 0; j < iterations; j++) {
    for (i = 2; i < N - 3; i++) {
      //if (i = 0) {
      //  U[i+1] = (2 + dx*dx)*U[1] - U[N-1];
      //}
      //if (i != 0) {  
        U[i+2] = (6*U[i]*dx*dx - 2)*(U[i+1] - U[i-1]) - U[i-2];
      }
  }  
  

  for (i = 0; i < N; i++) {
    printf("%lf\n", U[i]);
  }
  return 0;
}
