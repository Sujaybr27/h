#include <stdio.h>
#include <omp.h>

int fib[100],n;
void generate()
{
	fib[0]=0;
	fib[1]=1;
	for(int i = 2;i<n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
}
void printfib()
{
	for(int i = 0;i<n;i++)
	{
		printf("%d\t",fib[i]);
	}
}
int main()
{
	printf("Enter the number of elements");
	scanf("%d",&n);
	#pragma omp parallel sections
	{
		#pragma omp section
		generate();
		#pragma omp section
		printfib();
	}
	return 0;
}
