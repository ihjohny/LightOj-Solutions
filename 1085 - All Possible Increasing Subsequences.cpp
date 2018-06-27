//1085 - All Possible Increasing Subsequence
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
int arra[100100];
int tree[100100];
int ct;
void update(int index,int value)
{
	while(index<=ct)
	{
		tree[index]=(tree[index]+value)%1000000007;
		index+=(index&-index);
	}
}
int query(int index)
{
	int sum=0;
	while(index>0)
	{
		sum=(sum+tree[index])%1000000007;
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
		int n;
		ct=0;
		int result=0,ans=0;
		scanf("%d",&n);
		memset(arra,0,sizeof arra);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arra[i]);
		}
		memset(tree,0,sizeof tree);
		map<int,int>mp;
		vector<int>tmp(arra,arra+n);
		
		sort(tmp.begin(),tmp.end());
		
		for(int i=0;i<n;i++)
		{
			if(mp.count(tmp[i])==0)
				mp[tmp[i]]=++ct;
		}
		
		for(int i=0;i<n;i++)
		{
			result=(query(mp[arra[i]]-1)+1);
			ans=(ans+result)%1000000007;
			update(mp[arra[i]],result);
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
