//1087 - Diablo 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 1000050

int arra[SZ];
int tree[SZ*3];
int A[SZ];
int n=0,q=0,ts=0;

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=A[b];
		return ;
	}
	int left=(node*2);
	int right=(node*2)+1;
	init(left,b,(b+e)/2);
	init(right,((b+e)/2)+1,e);
	tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e, int i,int j)
{
	if(b>=i && e<=j)
		return tree[node];
	if(b>j || e<i)
		return 0;

	int left=(node*2);
	int right=(node*2)+1;
	
	int p1=query(left,b,(b+e)/2,i,j);
	int p2=query(right,((b+e)/2)+1,e,i,j);
	
	return p1+p2;
}

void update(int node, int b,int e, int index, int value)
{
		if(index<b || index>e)
		{
			return;
		}
		if(b==e)
		{
			tree[node]=value;
			return;
		}			
		int left=node*2;
		int right=(node*2)+1;
		update(left,b,(b+e)/2,index,value);
		update(right,((b+e)/2)+1,e,index,value);
		tree[node]=tree[left]+tree[right];
}

int binary_search(int low,int high,int value)
{
	if(low>high)
		return 0;
	else
	{
		int mid=(low+high)/2;
		int res=query(1,1,ts,1,mid);
		if(value==res)
		{
			if(A[mid]==1)
				return mid;
			else
			{
				while(A[mid]==0 && mid!=0)
				{
					mid--;
				}
				return mid;
			}
		}	
		else if(value<res)
		{
			return binary_search(low,mid-1,value);
		}
		else
		{
			return binary_search(mid+1,high,value);
		}
	}
}


int main()
{
	int x;
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		memset(arra,0,sizeof arra);
		memset(tree,0,sizeof tree);
		memset(A,0,sizeof A);
		n=0;
		q=0;
		ts=0;
		scanf("%d",&n);
		scanf("%d",&q);
		ts=n+q+5;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arra[i]);
			A[i]=1;
		}
		init(1,1,ts);
		printf("Case %d:\n",t);
		
		char comand;
		int in;
		
		for(int j=1;j<=q;j++)
		{
			getchar();
			scanf("%c",&comand);
			scanf("%d",&in);
			
			if(comand=='c')
			{
				int index = binary_search(1,n,in);
				if(index==0)
					printf("none\n");
				else
				{ 
					printf("%d\n",arra[index]);
					A[index]=0;
					update(1,1,ts,index,0);
				}
			}
			else if(comand=='a')
			{
				n++;;
				arra[n]=in;
				A[n]=1;
				update(1,1,ts,n,1);
			}
		}
	}
	return 0;
}
