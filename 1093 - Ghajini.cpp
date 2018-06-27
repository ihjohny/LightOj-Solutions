//1093 - Ghajini
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ  1000025
#define INF 10000000
int main()
{
	int x;
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		int n,d;
		int numbers[SZ];
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&numbers[i]);
		}
		
		int dif[SZ]={0};
		int min=INF;
		int min2=INF;
		int max=0;
		int max2=0;
		int k=1;
		int maxindex=0;
		int minindex=0;
		for(int i=1;i<=n;i++)
		{
			
			if(i>d)
			{
				max=max2;
				min=min2;
				
				if(i-d==maxindex)
				{
					max2=0;
				}
				if(i-d==minindex)
				{
					min2=INF;
				}
			}
			
			if(numbers[i]>max)
			{
				max=numbers[i];
				maxindex=i;
			}
			if(numbers[i]<min)
			{
				min=numbers[i];
				minindex=i;
			}
			
			if(i!=1)
			{
				if(numbers[i]>max2)
					max2=numbers[i];
				if(numbers[i]<min2)
					min2=numbers[i];
			}
			
			
			if(i<=d)
			{
				dif[k]=max-min;
			}
			else
			{
				dif[++k]=max-min;
			}
				
		}
		
		int result=0;
		for(int y=1;y<=n-d+1;y++)
		{
			if(dif[y]>result)
			{
				result=dif[y];
			}
		}
		printf("Case %d: %d\n",t,result);
	}
	return 0;
}
