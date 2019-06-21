//1041 - Road Construction 
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
//#define INF 99999999
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
#define SIZE 500005
struct Edge{
	int u,v,cost;
};
bool operator<(Edge a,Edge b){
	return a.cost<b.cost;
}
vector<Edge> E;
int p[1000];
int find(int x)
{
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}

int kruskal(int n,int m){
	forlp0(i,1000)	p[i]=i;
	sort(E.begin(),E.end());
	int ans=0;
	int c=0;
	forlp0(i,(int)E.size()){
		if( find(E[i].u)!=find(E[i].v) ){
			p[find(E[i].u)]=find(E[i].v);
			ans=ans+E[i].cost;
			c++;
		}
	}
	if(c==n-1) 
		return ans;
	else
		return -1;
}

int main()
{
	int T,m,cost,n,result;
	string source,dest;
	sfint(T);
	forlp1(i,T){
		memset(p,0,sizeof p);
		map<string,int>Map;
		vector<Edge>e; swap(e,E);
		n=1;
		result=-1;
		sfint(m);
		forlp1(j,m){
			cin>>source;
			if(Map[source]==0)
				Map[source]=n++;
			cin>>dest;
			if(Map[dest]==0)
				Map[dest]=n++;
			sfint(cost);
						
			Edge temp;
			temp.u=Map[source];
			temp.v=Map[dest];
			temp.cost=cost;
			E.push_back(temp);
			temp.u=Map[dest];
			temp.v=Map[source];
			temp.cost=cost;
			E.push_back(temp);
		}
		n=n-1;
		result=kruskal(n,m);
	//	cout<<" n = "<<n;
		if(result==-1)
			printf("Case %d: Impossible\n",i);
		else
			printf("Case %d: %d\n",i,result);
	}
	return 0;
}
