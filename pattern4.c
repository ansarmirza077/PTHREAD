#include<stdio.h>
#define limit n
int main()
{
	int i,j,n;
	printf("Enter n value");
	scanf("%ld",n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
		return 0;
	}
}	
