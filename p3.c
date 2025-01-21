#include <stdio.h>
#include<omp.h>

int main()
{
	int n;
	printf("Enter the number of steps");
	scanf("%d",&n);
	double pi = 0.0, step = 1.0/n;
	#pragma omp parallel
	{
		double sum = 0.0, x;
		#pragma omp for
			for(int i = 0;i<n;i++)
			{
				x = (i+0.5)*step;
				sum = 4.0/(1.0+x*x);
			}
			pi += sum;
		#pragma omp atomic
		pi *= step;
	}
	printf("%.2lf",pi);
}
