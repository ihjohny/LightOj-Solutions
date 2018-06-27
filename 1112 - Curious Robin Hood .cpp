//1112 - Curious Robin Hood 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;

void update(int index,int x,int (*tree),int n)
{
	while(index<=n)
	{
		(tree)[index]+=x;
		index+=(index & -index);
	}
}
int sum(int index,int tree[])
{
	int res=0;
	while(index>0)
	{
		res+=tree[index];
		index-=(index & -index);
	}
	return res;
}
int main()
{
	int x;
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		int sacks[100005],tree[100005]={0};
		for(int j=0;j<n;j++)
		{
			scanf("%d",&sacks[j]);
		}
		for(int j=0;j<n;j++)
		{
			update(j+1,sacks[j],tree,n);
		}
		
		printf("Case %d:\n",i);
		for(int j=1;j<=q;j++)
		{
			int id;
			scanf("%d",&id);
	
			if(id==1)
			{
				int ii;
				scanf("%d",&ii);
				printf("%d\n",sacks[ii]);
				update(ii+1,-sacks[ii],tree,n);
				sacks[ii]=0;
			}
			else if(id==2)
			{
				int ii,vv;
				scanf("%d%d",&ii,&vv);
				update(ii+1,vv,tree,n);
				sacks[ii]+=vv;
			}
			else if(id==3)
			{
				int ii,jj,res=0;
				scanf("%d%d",&ii,&jj);
				res=sum(jj+1,tree)-sum(ii,tree);			
				printf("%d\n",res);
			}
		}
	}
	return 0;
}
