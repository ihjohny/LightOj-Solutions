//LightOj 1047 Neighbor House
//Undefined_Error
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<28
#define ll long long 
#define SZ 100005
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
int house[22][4];
int dp[1000][1000];
int n;
int RockClimbing(int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<3 && house[i][j]!=0)
	{
		if(dp[i][j]!=-1) return dp[i][j];
		int ret=INF;
		ret=min(ret,RockClimbing(i+1,j-1)+house[i][j]);
		ret=min(ret,RockClimbing(i+1,j+1)+house[i][j]);
		ret=min(ret,RockClimbing(i+1,j+2)+house[i][j]);
		ret=min(ret,RockClimbing(i+1,j-2)+house[i][j]);
		
		dp[i][j]=ret;
		return dp[i][j];
	}
	else if(i>=n )
	{
		return 0;
	}
	else return INF;
}

int main()
{
	int T;
	sfint(T);
	forlp1(t,T)
	{
		memset(house,0,sizeof house);
		memset(dp,-1,sizeof dp);
		sfint(n);
		forlp0(i,n)
		{
			sfint3(house[i][0],house[i][1],house[i][2]);
		}
		int result=min(RockClimbing(0,2),min(RockClimbing(0,0),RockClimbing(0,1)));
		
/*		
		forlp0(u,100)
			forlp0(k,100)
				cout<<" "<<dp[u][k];
*/ 
		printf("Case %d: %d\n",t,result);
	}
	return 0;
}
