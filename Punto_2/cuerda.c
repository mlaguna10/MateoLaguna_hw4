#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define T 40
#define rho 10
#define L 100
#define deltax 1
#define deltat 0.2
#define c 2

int main()
{
  int t = 200;
  float *uinicial;
  uinicial = malloc(100000);

  float *u_jb;
  u_jb = malloc(100000);

  float *u_jn;
  u_jn = malloc(100000);
  
  float alpha = c*(deltat/deltax);
  
  int i;
  int puntos = L/deltax;
  for(i=0;i<puntos;i++)
    {
      if(i <= 0.8*L)
	{
	  uinicial[i] = 1.25*i/L;
	  printf("%f \n",uinicial[i]);
	}
      else
	{
	  uinicial[i] = 5.0 - 5.0*i/L;
	  printf("%f \n",uinicial[i]);
	    
	}
    }

  float j;
  int w = 0;
  for(j=0;j<t;j+=deltat)
    {
      for(i=0;i<puntos;i++)
	{
	  if(j==0)
	    {
	      u_jn[i] = (float) uinicial[i] + ((pow(alpha,2))*(uinicial[(i+1)%1000]-2*uinicial[i] + uinicial[i-1]))/2;
	    }
	  else
	    {
	      u_jn[i] = (float)2*(1-pow(alpha,2))*uinicial[i] - u_jb[i] +(pow(alpha,2))*(uinicial[(i+1)%1000] + uinicial[i-1]);
	    }
	    
	  if(w%50==0)
	    {
	      printf("%f \n",u_jn[i]);
	    }
	}

      for(i=0;i<100;i++)
	{
	  u_jb[i] = uinicial[i];
	}
      for(i=0;i<100;i++)
	{
	  uinicial[i] = u_jn[i];
	}

      w+=1;
    }
  return 0;
}
