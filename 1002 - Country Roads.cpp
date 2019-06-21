//1002 - Country Roads 
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
};
bool operator<(Edge a,Edge b){
	return a.w<b.w;
}
vector<Edge>E;
int p[1000];
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
void result(int t,int n){
	vector<PII> spanningTree[1000];
	int visited[1000]={0};
	int maxDistance[1000];
	memset(maxDistance,0,sizeof maxDistance);

	forlp0(i,1000){
		p[i]=i;
	}
	sort(E.begin(),E.end());
	int size=E.size();
	forlp0(i,size){
		if(find(E[i].u)!=find(E[i].v)){
			p[find(E[i].u)]=find(E[i].v);
			spanningTree[E[i].u].push_back(make_pair(E[i].v ,E[i].w) );
			spanningTree[E[i].v].push_back(make_pair(E[i].u ,E[i].w) );
		}
	}
	
	queue<int> q;
	q.push(t);
	visited[t]=1;
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<(int)spanningTree[u].size();i++)
		{ 
			if(visited[spanningTree[u][i].first]==0)
			{
				q.push(spanningTree[u][i].first);
				visited[spanningTree[u][i].first]=1;
				maxDistance[spanningTree[u][i].first] =max( maxDistance[u],spanningTree[u][i].second );
			}
		}
	}
	
	forlp0(i,n){
		if(i==t)
			cout<<0<<endl;
		else if(maxDistance[i]==0)
			cout<<"Impossible"<<endl;
		else
			cout<<maxDistance[i]<<endl;
	}
}
int main()
{
	int testCase;
	sfint(testCase);
	forlp0(i,testCase){
		memset(p,0,sizeof p);
		vector<Edge>e; swap(e,E);
		int n,m,t;
		sfint2(n,m);
		forlp0(j,m){
			int u,v,w;
			sfint3(u,v,w);
			
			Edge temp;
			temp.u=u;
			temp.v=v;
			temp.w=w;
			E.push_back(temp);
			temp.u=u;
			temp.v=v;
			temp.w=w;
			E.push_back(temp);
			
		}
		sfint(t);
		//
		printf("Case %d:\n",i+1);
		result(t,n);
	}
    return 0;
}
