//1082 - Array Queries 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define size 100050
int arra[size];
int tree[size*3];

void init(int node, int b, int e)
{
	if(b==e)
	{
		tree[node]=arra[b];
		return ;
	}
	int mid=(b+e)/2;
	int left=node*2;
	int right=node*2+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=min(tree[left],tree[right]);
}
int query(int node, int b, int e, int i,int j)
{
	if(b>j||e<i )
	{
		return 1000000;
	}
	if(b>=i&&e<=j)
	{
		return tree[node];
	}
	int mid=(b+e)/2;
	int left=node*2;
	int right=node*2+1;
	int p1=query(left,b,mid,i,j);
	int p2=query(right,mid+1,e,i,j);
	return min(p1,p2);
}
int main()
{
	int x;
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		memset(arra,0,sizeof arra);
		memset(tree,0,sizeof tree);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arra[i]);
		}
		init(1,1,n);
		printf("Case %d:\n",t);
		for(int i=1;i<=q;i++)
		{
			int ii,jj;
			scanf("%d%d",&ii,&jj);
			printf("%d\n",query(1,1,n,ii,jj));
		}
	}
	return 0;
}
