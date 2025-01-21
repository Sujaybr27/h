# include <stdio.h>
# include <omp.h>

int main()
{
	int n;
	printf("Enter the number of categories");
	scanf("%d",&n);
	char name[50][n];
	double price[n], total;
	for (int i = 0; i<n; i++)
	{
		printf("Enter the category");
		scanf("%s",&name[i]);
		printf("Enter the price");
		scanf("%lf",&price[i]);
	}
	#pragma omp parallel for reduction (+:total)
	for (int i = 0; i<n; i++)
	{
		total += price[i];
	}
	printf("The total amount is %.2lf",total);
	return 0;
}
