//1067 - Combinations 
//Love Coffe and Code
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF 1<<28
#define lli long long int
#define ulli unsigned long long int
#define MX 1000000000
#define SIZE 1000000
#define sfint(a) scanf("%d",&a)
#define sfllint(a) scanf("%lld",&a)
#define sfch(a) scanf("%c",&a)
#define sfchsq(a) scanf("%s",a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfllint2(a,b) scanf("%lld%lld",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define forlp2(i,n) for(int i=2;i<=n;i++)
#define forlpa(i,a,n) for(int i=a;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
#define rvforlp1(i,n) for(int i=n-1;i>0;i--)
#define mem(a,b) memset(a, (b), sizeof(a))
#define mem2d(a,n,m,b) memset(a, (b), sizeof(a[0][0] * n * m))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define SZ 1000009
typedef pair<int,int> PII;

const long long  MOD = 1000003;
ulli fact[SZ];

void clcFact(){
	fact[0] = 1;
	forlp1(i,SZ){
		fact[i] = (fact[i-1]* i) % MOD;
	}
}


ulli bigMod(ulli n, ulli p){
	if( p == 0) return 1;
	if( p%2 == 0){
		int res = bigMod(n,p/2);
		return ((res%MOD)*(res%MOD)) % MOD;
	}
	else
		return ((n%MOD)*(bigMod(n,p-1)%MOD)) % MOD;
}

ulli nCr(int n, int k){
	int s = n - k;
	if(k == 0) 
		return 1;
	ulli ans = ((fact[k]%MOD)*(fact[s]%MOD))%MOD;
	ans = bigMod(ans,MOD-2);
	ans = ((fact[n]%MOD)*(ans%MOD))%MOD;
	
	return ans;
}

int main() {
IOS

	clcFact();	//Pre calculate all factorial mod
	int testCase;
	sfint(testCase);
	
	forlp1(t,testCase){
		int n,k;
		sfint2(n,k);
			
		ulli result = nCr(n,k);
		
		cout<<"Case "<<t<<": "<<(result)<<endl;
	}
	
    return 0;
}
