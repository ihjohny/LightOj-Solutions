//1029 - Civil and Evil Engineer
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<28
#define ll long long
#define SZ 100009
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define forlpa(i,a,n) for(int i=a;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int,int> PII;
#define SIZE 100005
//#define INF 99999999
struct Edge{
	int u,v,w;
	Edge(int a,int b,int c){
		u=a;v=b;w=c;
	}
};
bool operator <(Edge a,Edge b){return a.w<b.w;}
vector<Edge> E;
int p[10000];
int find(int x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
void kruskal(int n){
	int minispn=0;
	int maxspn=0;
	forlp0(i,1000)	p[i]=i;
	sort(E.begin(),E.end());
	forlp0(i,(int)E.size()){
		if( find(E[i].u)!=find(E[i].v) ){
			p[find(E[i].u)]=find(E[i].v);
			minispn+=E[i].w;
		}
	}
	forlp0(i,1000)	p[i]=i;
	rvforlp(i,(int)E.size()){
		if( find(E[i].u)!=find(E[i].v) ){
			p[find(E[i].u)]=find(E[i].v);
			maxspn+=E[i].w;
		}
	}
	
	if( (maxspn+minispn)%2==0 )	printf("%d\n",(maxspn+minispn)/2);
	else{
		printf("%d/2\n",maxspn+minispn);
	}
}
int main()
{
	int t,n,u,v,w;
	sfint(t);
	forlp1(i,t){
		memset(p,0,sizeof p);
		vector<Edge>e; swap(e,E);
		sfint(n);
		while(1){
			sfint3(u,v,w);
			if(u==0 && v==0 && w==0)
				break;
			Edge test(u,v,w);
			E.push_back(test);
			Edge test1(v,u,w);
			E.push_back(test1);
		}
		printf("Case %d: ",i);
		kruskal(n);
	}
	return 0;
}
