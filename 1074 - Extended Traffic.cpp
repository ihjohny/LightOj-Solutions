//1074 - Extended Traffic
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
struct edge{
	int u,v,w;
};
vector<edge>E;
int dist[500];
int busy[500];
void bellmanford(int source,int n){
	forlp0(i,n+1)
		dist[i]=INF;
	dist[source]=0;
	int size=E.size();
	forlp0(i,n-1){
		forlp0(j,size){

			if(dist[E[j].v] > dist[E[j].u]+E[j].w && dist[E[j].u]!=INF){
				dist[E[j].v] = dist[E[j].u]+E[j].w;
			}
		}
	}
	forlp0(j,size){
		if(dist[E[j].v] > dist[E[j].u]+E[j].w && dist[E[j].u]!=INF){
			dist[E[j].v] = -INF;
		}
	}
}
int main()
{
	int testCase;
	sfint(testCase);
	forlp1(i,testCase){
		memset(busy,0,sizeof busy);
		vector<edge>e; swap(e,E);
		int n,m,q,dest;
		sfint(n);
		forlp1(j,n){
			sfint(busy[j]);
		}
		sfint(m);
		forlp1(j,m){
			int source,dest;
			sfint2(source,dest);
			edge test;
			test.u=source;
			test.v=dest;
			test.w=((busy[dest]-busy[source])*(busy[dest]-busy[source])*(busy[dest]-busy[source]));
			E.push_back(test);
		}
		sfint(q);
		printf("Case %d:\n",i);
		bellmanford(1,n);
		forlp1(j,q){
			sfint(dest);
			if(dist[dest]<3 || dist[dest]==INF)
				printf("?\n");
			else
				printf("%d\n",dist[dest]);
		}
	}
	return 0;
}
