# include <stdio.h>
#include <omp.h>

int main()
{
	int n, m;
	printf("Enter the size of matrix");
	scanf("%d",&n);
	printf("Enter the size of vector");
	scanf("%d",&m);
	if (m != n)
	{
		printf("Matrix multiplication is not possible");
		return 0;
	}
	int mat[n][n], vec[m], result[m];
	printf("Enter the elements of the matrix");
	for(int i = 0; i<n; i++)
	{
		for(int j= 0; j<n; j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(int j= 0; j<n; j++)
	{
		scanf("%d",&vec[j]);
	}
	#pragma omp parallel
	{
		for(int i = 0; i<n; i++)
	{
		result[i] = 0;
		for(int j= 0; j<n; j++)
		{
			result[i] += mat[i][j] * vec[j];
		}
	}
	}
	for(int j= 0; j<n; j++)
		{
			printf("%d",result[j]);
		}
	return 0;
}
