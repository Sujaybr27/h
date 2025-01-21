#include <stdio.h>
#include <omp.h>

int main()
{
	int n;
	double cg[100],maxi;
	printf("Enter the number of students");
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%lf",&cg[i]);
	#pragma omp parallel for reduction(max:maxi)
	for(int i = 0;i<n;i++)
	{
		if (maxi<cg[i])
			maxi = cg[i];
	}
	printf("%.2lf",maxi);
	return 0;
}
