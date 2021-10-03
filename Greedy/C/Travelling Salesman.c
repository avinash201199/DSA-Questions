#include<stdio.h>
#include<time.h>
int ary[10][10],completed[10],n,cost=0;
void takeInput()
{
	int i,j;
	printf("Enter the number of villages: \n");
	scanf("%d",&n);
	printf("Enter the Cost Matrix\n");
	for(i=0;i < n;i++)
	{
		printf("Enter Elements of Row: %d\n",i+1);
		for( j=0;j < n;j++)
		scanf("%d",&ary[i][j]);
		completed[i]=0;
	}
 	printf("\n\nThe cost list is:");
	for( i=0;i < n;i++)
	{
		printf("\n");
		for(j=0;j < n;j++)
		printf("\t%d",ary[i][j]);
	}
}
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
		if(ary[c][i]+ary[i][c] < min)
		{
			min=ary[i][0]+ary[c][i];
			kmin=ary[c][i];
			nc=i;
		}
	}
	if(min!=999)
	cost+=kmin;
	return nc;
}
void mincost(int city)
{
	int i,ncity;
	completed[city]=1;
	printf("%d--->",city+1);
	ncity=least(city);
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=ary[city][ncity];
		return;
	}
	mincost(ncity);
}
void main()
{
	takeInput();
	printf("\nThe Path is:\n");
	mincost(0); 
	printf("\nMinimum cost is %d\n ",cost);
}
