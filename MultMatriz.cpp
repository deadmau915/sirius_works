#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ShowM(int f, int c, int **m)
{
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Mult(int f, int c, int f1, int c1, int **m, int **n, int **r)
{
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c1;j++)
		{
			r[i][j]=0;
			for(int a=0;a<f1;a++)
			{
				r[i][j]=r[i][j]+(m[i][a] * n[a][j]);
			}
		}
	}
}

void LlenarM(int f, int c, int** m)
{
	for(int i=0; i<f; i++)
	{
		for(int j=0; j<c; j++)
		{
			m[i][j]=rand()%5;
		}
	}
}

int main()
{
	int f=3, c=2, f1=2, c1=4;
	srand(time(NULL));
	
	int**m=(int**) malloc(sizeof(int*)*f);
	for(int i=0; i<f;i++)
	{
		m[i]= (int*)malloc(sizeof(int*)*c);
	}
	
	int**n=(int**) malloc(sizeof(int*)*f1);
	for(int i=0; i<f1;i++)
	{
		n[i]= (int*)malloc(sizeof(int*)*c1);
	}
	
	LlenarM(f, c, m);
	ShowM(f, c, m);
	
	LlenarM(f1, c1, n);
	ShowM(f1, c1, n);
	
	if(c == f1)
	{
		int**r=(int**) malloc(sizeof(int*)*f);
		for(int i=0; i<f;i++)
		{
			r[i]= (int*)malloc(sizeof(int*)*c1);
		}
		
		Mult(f, c, f1, c1, m, n, r);
		ShowM(f, c1, r);
	}
	else
	{
		printf("Is not possible");
	}
	
}
