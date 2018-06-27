//1164 - Horrible Queries
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
long long int arra[SZ];
struct info
{
	long long int sum;
	long long int prop;
}tree[SZ*3+1];

void update(int node, int b, int e, int i,int j,long long int value)
{
	if(b>j || e<i)
		return;
	if(b>=i && e<=j)
	{
		tree[node].sum=tree[node].sum+(e-b+1)*value;
		tree[node].prop=tree[node].prop+value;
		return;
	}
	int mid=(b+e)/2;
	int left=node<<1;
	int right=(node<<1)+1;
	update(left,b,mid,i,j,value);
	update(right,mid+1,e,i,j,value);
	tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
long long int query(int node,int b,int e, int i,int j,long long int carry=0)
{
	if(b>j || e<i)
		return 0;
	if(b>=i && e<=j)
		return tree[node].sum+(e-b+1)*carry;
	int mid=(b+e)/2;
	int left=node<<1;
	int right=(node<<1)+1;
	long long int p1=query(left,b,mid,i,j,carry+tree[node].prop);
	long long int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
	return p1+p2;
}

int main()
{
	int x;
	scanf("%d",&x);
	
	for(int t=1;t<=x;t++)
	{
		memset(arra,0,sizeof arra);
		memset(tree,0,sizeof tree);
		int n=0;
		int q=0;
		printf("Case %d:\n",t);
		scanf("%d%d",&n,&q);

		for(int i=1;i<=q;i++)
		{
			int operation,x,y;
			long long v;
			long long int ans=0;
			scanf("%d",&operation);
			if(operation==0)
			{
				scanf("%d%d%lld",&x,&y,&v);
				update(1,0,n-1,x,y,v);
			}
			else if(operation==1)
			{
				scanf("%d%d",&x,&y);
				ans=query(1,0,n-1,x,y);
				printf("%lld\n",ans);
			}
		}
		
	}
	return 0;
}

