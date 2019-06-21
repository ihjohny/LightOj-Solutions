//Prime Factorization using Sieve O(log n) 
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
inline int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
lli mod = 1000000007;

vector<PII> primeFactors(lli n){
	vector<PII> primeStore;
	int count = 0;
	while(n%2 == 0){
		n/=2;
		count++;
	}
	if(count)
		primeStore.pb(mp(2,count));
	for(int i=3; i<=sqrt(n); i+=2){
		count = 0;
		while(n%i == 0){
			count++;
			n/=i;
		}
		if(count)
			primeStore.pb(mp(i,count));
	}
	if(n>2){
		primeStore.pb(mp(n,1));
	}
	return primeStore;
}

lli bigMod(lli n, lli m){
	if( m == 0 ) return 1;
	if( m%2 == 0){
		lli ret = bigMod(n,m/2);
		return ((ret%mod)*(ret%mod))%mod;
	}
	return ((n%mod)*((bigMod(n,m-1))%mod))%mod;
}

lli solve(lli n, lli m){
	vector<PII> primeStore;
	lli sum = 1;
	primeStore = primeFactors(n);
	forlp0(i,(int)primeStore.size()){
		if(primeStore[i].first % mod ==0)
			return 1;
		lli power = (primeStore[i].second*m)+1;
		lli up = bigMod(primeStore[i].first,power)-1;
		lli down = bigMod((primeStore[i].first-1),mod-2);
		lli s = ((up%mod)*(down%mod)) % mod;
		sum = ((sum%mod)*(s%mod))%mod;
	}
	return sum;
}

int main(){
IOS
	int testCase;
	sfint(testCase);
	forlp1(t, testCase){
		lli n,m;
		sfllint2(n,m);
		lli result = solve(n,m);
		printf("Case %d: %lld\n",t,result);
	}
	return 0;
}

