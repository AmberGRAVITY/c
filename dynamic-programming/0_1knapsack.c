#include<stdio.h>
#include<conio.h>

int max(int a,int b)
{
	return((a>b)?a:b);
}
int knap(int w[],int v[],int W,int n)
{
	int i,j,b[100][200],x[10],sum=0;
	for(i=0;i<=W;i++)
	{
		b[0][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		b[i][0]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			if((j-w[i])<0)
			{
				b[i][j]=b[i-1][j];
			}
			else
			{
				b[i][j]=max(b[i-1][j],b[i-1][j-w[i]]+v[i]);
			}
		}
	}
	printf("\n TAble of 0/1 knapsack problem:\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			printf("%4d",b[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)

	x[i]=0;
	i=n;
	j=W;
	while(i>0 && j>0)
	{
		if(b[i][j]!=b[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		i--;
	}
	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			 sum=sum+v[i];
		}
	}
	printf("\n Total profit is :: %d",sum);
	return 0;
}
int main()
{
	int w[10],v[10],i,W,n,b[100][200],j;
	printf("\t 0/1 KNAPSACK PROBLEM\n\n");

	printf("\n Enter the no. of items:");
	scanf("%d",&n);
	printf("\n Enter the no. of weights:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("\n Enter the no. of value:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
	}
	printf("\n Enter the maximum weight:");
	scanf("%d",&W);
	knap(w,v,W,n);
  return 0;
}