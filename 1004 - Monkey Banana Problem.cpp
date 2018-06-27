//1004 - Monkey Banana Problem 
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
#define forlpa(i,a,n) for(int i=a;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
int diamond[1000][1000];
int dp[1000][1000];
int N; 

int RockClimbing(int i,int j)
{
	if(i>=1 && j>=1 && diamond[i][j]!=0)
	{
		if(dp[i][j]!=-1) return dp[i][j];
		int ret=-INF;
		ret=max(ret,RockClimbing(i+1,j)+diamond[i][j]);
		if(i<N)
			ret=max(ret,RockClimbing(i+1,j+1)+diamond[i][j]);
		else
		{
			ret=max(ret,RockClimbing(i+1,j-1)+diamond[i][j]);
		}
		return dp[i][j]=ret;
	}
	else 
		return 0;
}

int main()
{
	int T;
	sfint(T);
	forlp1(t,T)
	{
		memset(dp,-1,sizeof dp);
		memset(diamond,0,sizeof diamond);
		sfint(N);
		forlp1(i,2*N-1)
		{
			if(i<=N)
			{
				forlp1(j,i)
				{
					sfint(diamond[i][j]);
				}
			}
			else
			{
				forlp1(j,2*N-i)
				{
					sfint(diamond[i][j]);
				}
			}
		}
		/*printing input
		forlp1(i,2*N-1)
		{
			forlp1(j,10)
			{
				cout<<diamond[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		int result=RockClimbing(1,1);
		printf("Case %d: %d\n",t,result);
	}
	return 0;
}
