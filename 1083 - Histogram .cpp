//1083 - Histogram 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
#define MX 10000000

int tree[3*SZ];
int arra[SZ];
int N;
int check(int i,int j)
{ 	
	if(i == -1) return j;
	if(j == -1) return i;
	if(arra[i]<arra[j])
		return i;
	else 
		return j;
}
void init(int node, int b, int e)//segment tree implemention
{
	if(b==e)
	{
		tree[node]=b;
		return ;
	}
	int mid=(b+e)/2;
	int left=node*2;
	int right=(node*2)+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=check(tree[left],tree[right]);
	
}

int query(int node,int b,int e,int i,int j)
{
	if(b>=i && e<=j)	{
		return tree[node];
	}
	if(e<i||b>j)
	{
		return -1;
	}
	int mid=(b+e)/2;
	int left=(node*2);
	int right=(node*2)+1;
	int p1=query(left,b,mid,i,j);
	int p2=query(right,mid+1,e,i,j);
	return check(p1,p2);
}

int divide_conquer(int i,int j)
{
	if(i>j) return -1;
	if(i==j)return arra[i];
	
	int midindex=query(1,1,N,i,j);
	
	int p1=divide_conquer(i,midindex-1);
	int p2=divide_conquer(midindex+1,j);
	
	int ans=max(p1,p2);
	return max(ans,(arra[midindex]*(j+1-i)));

}

int main()
{
	int x;
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		memset(arra,0,sizeof arra);
		memset(tree,0,sizeof tree);
		N=0;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&arra[i]);
		}
		init(1,1,N);
		
		int ans;
		ans=divide_conquer(1,N);
		printf("Case %d: %d\n",t,ans);
		
	}
	return 0;
}
