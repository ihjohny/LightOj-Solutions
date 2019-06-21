//1014 - Ifter Party 
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
#define SZ 300009
typedef pair<int,int> PII;
inline int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}

int main(){
IOS
	
	int testCase;
	sfint(testCase);
	forlp1(t,testCase){
		lli p,l;
		sfllint2(p,l);
		
		//solve
		vector<lli> container;
		if(p-l <= l || p == 0)
		{
			cout<<"Case "<<t<<": impossible"<<endl;
			continue;
		}
		else{
			lli num = p - l;
			for(lli i=1; (i*i)<=num; i++){
				if(num % i == 0){
					if(i*i == num && i>l){
						container.pb(i);
					}
					else if( i>l){
						container.pb(i);
						container.pb(num/i);
					}
					else if(num/i > l){
						container.pb(num/i);
					}
				}
			}
		}
				
		sort(container.begin(),container.end());
		
		cout<<"Case "<<t<<":";
		forlp0(i,(int)container.size()){
			cout<<" "<<container[i];
		}
		cout<<endl;
		
	}
	return 0;
}

