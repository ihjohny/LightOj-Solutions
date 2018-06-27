//LightOj 1231
//Undefined_Error
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long 
#define SZ 100005
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)

int coin[100];
int C[100];
int dp[100][1005];
int totalCoin,k;

int call(int i, int amount)
{
	if(i>=totalCoin)
	{
		if(amount==0) return 1;
		else return 0;
	}
	int ret1=0;
	if(dp[i][amount]!=-1) return dp[i][amount];
	for(int j=1;j<=C[i];j++)
	{
		if(amount-(coin[i]*j)>=0)
		{
			ret1+=(call(i+1,amount-(coin[i]*j)))%mod;
		}
		else break;
	}			
	ret1+=(call(i+1,amount))%mod;
	dp[i][amount]=(ret1)%mod;
	return dp[i][amount];
}

int main()
{
	int T;
	sfint(T);
	forlp1(t,T)
	{
		memset(dp,-1,sizeof dp);
		memset(coin,0,sizeof (int));
		memset(C,0,sizeof (int));
		scanf("%d%d",&totalCoin,&k);
		forlp0(i,totalCoin)
			scanf("%d",&coin[i]);
		forlp0(i,totalCoin)
			scanf("%d",&C[i]);
		printf("Case %d: %d\n",t,call(0,k)%mod);
	}
	return 0;
}
