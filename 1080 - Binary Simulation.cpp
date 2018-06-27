//1080 - Binary Simulation
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
int tree[100005];
int n;

void update(int index,int value)
{
	while(index<=n)
	{
		tree[index]+=value;
		index+=(index&-index);
	}
}
int query(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=tree[index];
		index-=(index&-index);
	}
	return sum;
}
int main()
{
	int x;
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		char binary[100005];
		scanf("%s ",binary);
		int q;
		scanf("%d",&q);
		n=strlen(binary);
		memset(tree,0,sizeof tree);
		printf("Case %d:\n",t);
		for(int i=0;i<q;i++)
		{
			getchar();
			char id;
			scanf("%c",&id);
			//getchar();
			if(id=='I')
			{
				int i,j;
				scanf("%d%d",&i,&j);
				update(i,1);
				update(j+1,-1);
			}
			else if(id=='Q')
			{
				int i;
				scanf("%d",&i);
				if(query(i)%2)
				{
					if(binary[i-1]=='0')
						printf("1\n");
					else if(binary[i-1]=='1')
						printf("0\n");
				}
				else
				{
					printf("%c\n",binary[i-1]);
				}
			}
		}
	}
	return 0;
}
