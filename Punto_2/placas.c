#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define L 0.05
#define l 0.02
#define d 0.01
#define h 0.0002
#define V_0 100
#define N 125000
#define dimension 250

int main()
{

  
  float *matriz;
  matriz = malloc(10000000);

  int j;
  int i;

  for(i=0;i<250;i++)
    {
      for(j=0;j<250;j++)
	{
	  int k = dimension*i + j;
	  if(k<250)
	    {
	      matriz[k] = 0;
	      //printf("%d \n",0);
	    }
	  else if(k%250==0)
	    {
	      matriz[k] = 0;
	      //printf("%d \n",0);
	    }
	  else if(k%250==249)
	    {
	      matriz[k] = 0;
	      //printf("%d \n",0);
	    }
	  else if(k > 62250 && k < 62499)
	    {
	      matriz[k] = 0;
	      //printf("%d \n",0);
	    }
	  else if(k>24824 && k<24924)
	    {
	      matriz[k] = -50;
	      //printf("%d \n",-50);
	    }
	  else if(k>37324 && k<37424)
	    {
	      matriz[k] = 50;
	      //printf("%d \n",50);
	    }
	  else
	    {
	      matriz[k] = 1;
	      //printf("%d \n",1);
	    }
	}
    }

  int k;
 
  for(k=0;k<N;k++)
    {
      for(i=1;i<249;i++)
	{
	  for(j=1;j<249;j++)
	    {
	      int q = dimension*i + j;
	      int jb = dimension*i + (j-1);
	      int jn = dimension*i + (j+1);
	      int ib = dimension*(i-1) + j;
	      int in = dimension*(i+1) + j;
	      if(matriz[q] == 50 || matriz[q] == -50)
		{
		  
		}
	      else
		{
		  matriz[q] = (matriz[jb]+matriz[jn]+matriz[ib]+matriz[in])/4.0;
		}
	    }
	}
    }

  int x;
  for(i=0;i<250;i++)
    {
      for(j=0;j<250;j++)
	{
	  x = dimension*i + j;
	  printf("%f \n",matriz[x]);
	}
    }

  //Parte del campo electrico

  

  for(i=1;i<249;i++)
	{
	  for(j=1;j<249;j++)
	    {
	      
	      int q = dimension*i + j;
	      int xn = dimension*i + (j+1);
	      int jn = dimension*(i+1) + j;
	      
	      //Derivada respecto a x (hacia la derecha)
	      float derivadax = -1*(matriz[xn]-matriz[q])/h;
	      //Derivada respecto a y (hacia arriba)
	      float derivaday = -1*(matriz[jn]-matriz[q])/h;
	      
	      printf("%f %f \n",derivadax,derivaday);
		
	    }
	}


  return 0;
}

