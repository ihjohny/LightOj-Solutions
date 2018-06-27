//1183 - Computing Fast Average
//Undefined_Error
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define sfint(a) scanf("%d",&a)
#define sf2int(a,b) scanf("%d%d",&a,&b)
#define ll long long 
#define SZ 1000050
#define MX 100000000
struct info
{
	int prop;
	ll int sum;
	info()
	{
		prop=-1;
		sum=0;
	}
}tree[SZ*3];

ll int gcd(ll int a,ll int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}

void update(int node,int b,int e,int i,int j,int value)
{
	if(i>e || j<b)
		return;
	if(b>=i && e<=j)
	{
		tree[node].sum=(e-b+1)*value;
		tree[node].prop=value;
		return;
	}
	int left=node*2;
	int right=(node*2)+1;
	int mid=(b+e)/2;
	if(tree[node].prop!=-1 and b!=e)
	{
		tree[left].prop=tree[node].prop;
		tree[right].prop=tree[node].prop;
		tree[left].sum=tree[node].prop*(mid-b+1);
		tree[right].sum=tree[node].prop*(e-mid);
		tree[node].prop=-1;
	}
	update(left,b,mid,i,j,value);
	update(right,mid+1,e,i,j,value);
	
	tree[node].sum=tree[left].sum+tree[right].sum;
	return ;
}

ll int query(int node,int b,int e,int i,int j,ll int carry=-1)
{
	if(i>e || j<b) return 0;
	if(b>=i && e<=j)
	{
		if(carry==-1)return tree[node].sum;
		else return carry*(e-b+1);
	}
	if(carry == -1) carry = tree[node].prop;
	
	int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    
    ll int p1 = query(Left, b, mid, i, j,carry);
    ll int p2 = query(Right, mid + 1, e, i, j,carry);
    
    return p1+p2;
}

void init(int n)
{
	for(int i = 0; i <= n*3; i++)
	{
        tree[i].sum = 0;
        tree[i].prop = -1;
    }
}

int main()
{
	int x;
	scanf("%d",&x);
	for(int t=0;t<x;t++)
	{
		int n,q,p,i,j,v;
		scanf("%d %d",&n,&q);
		init(n);
		printf("Case %d:\n",t+1);
		for(int ii=1;ii<=q;ii++)
		{
			scanf("%d",&p);
			if(p==1)
			{
				//cout<<"update operation"<<endl;
				scanf("%d %d %d",&i,&j,&v);
				update(1,0,n-1,i,j,v);
			}
			else
			{
				//cout<<"query operation"<<endl;
				scanf("%d %d",&i,&j);
			
				ll int aa=query(1,0,n-1,i,j);
				ll int bb=j-i+1;
				ll int gg=gcd(aa,bb);
				if(gg==0)
				{
					printf("%d\n",0);
				}
				else
				{
					int num=aa/gg;
					int den=bb/gg;
				
					if(den==1) printf("%d\n",num);
					else printf("%d/%d\n",num,den);
				}
			}
		}
	}
	return 0;
}
