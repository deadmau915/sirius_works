#include <stdio.h>
#include <malloc.h>

#define SIZE 1024

void VectorAdd(int *a, int *b, int *c)
{
	for(int i=0;i<SIZE;i++)
	c[i]=a[i]+b[i];
}

int main()
{
	int *a, *b, *c;
	
	a=(int *)malloc(SIZE*sizeof(int));
	b=(int *)malloc(SIZE*sizeof(int));
	c=(int *)malloc(SIZE*sizeof(int));
	
	for(int i=0;i<SIZE;i++)
	{
		a[i]=i;
		b[i]=i;
		c[i]=0;
	}
	
	VectorAdd(a, b, c);
	
	for(int i=0;i<10;i++)
		printf("c[%d] = %d\n",i,c[i]);
		
	free(a); free(b); free(c);
	
	return 0;
}
