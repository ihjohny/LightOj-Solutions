//1076 - Get the Containers 
//Undefined_Error
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define sfint(a) scanf("%d",&a)
#define sf2int(a,b) scanf("%d%d",&a,&b)
#define SZ 100005
#define MX 100000000

int main()
{
	int x,n,m,low,high,v[SZ];
	sfint(x);
	for(int t=1;t<=x;t++)
	{
		low=0,high=0;
		sf2int(n,m);
		for(int i=0;i<n;i++)
		{
			sfint(v[i]);
			if(low<v[i]) low=v[i];
			high+=v[i];
		}
		
		int mid,check,conti,ans=0,mxconti;
		while(low<=high)
		{
			mid=(low+high)/2;
			check=0,conti=0;
			mxconti=0;
			
			for(int i=0;i<n;i++)
			{
				if((conti+v[i])<=mid)
				{
					conti=conti+v[i];
					
					if(i==n-1 || (conti+v[i+1]>mid && i!=n-1))
					{
						if(mxconti<conti) mxconti=conti;
						conti=0;
						check++;
					}
				}
				else if(conti+v[i]>=mid || i==n-1)
				{
					if(mxconti<conti) mxconti=conti;
					conti=0;
					check++;
				}
			}
			
			if(check==m)
			{
				ans=mxconti;
				high=mid-1;			} 
			else if(check<m)
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		if(ans==0)
			ans=low;
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
