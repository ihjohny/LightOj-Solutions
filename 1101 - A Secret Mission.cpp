//1101 - A Secret Mission 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
#define MX 100000000
pair<int,int>parent[SZ];
int level[SZ];
int sp_table[SZ][22];
int sp_cost[SZ][22];
int kparent[SZ];
vector<pair<int,int> > gp[SZ];

struct edge
{
	int u,v,w;
};
bool operator<(edge a,edge b)
{
	return a.w<b.w;
}
vector<edge>E,R;

int find(int x)
{
	if(kparent[x]==x)
		return x;
	return kparent[x]=find(kparent[x]);
}
void kruskal(int n)
{
	for(int i=0;i<=n;i++)
	{
		kparent[i]=i;
	}
	sort(E.begin(),E.end());
	int ans=0;
	int size=E.size();
	int cnt=0;
	for(int i=0;i<size;i++)
	{
		if(find(E[i].v)!=find(E[i].u))
		{
			kparent[kparent[E[i].u]]=kparent[E[i].v];
			ans+=E[i].w;
			R.push_back(E[i]);
			if(cnt == n-1)
                break;
			
		}
	}
}


void dfs(int from,int u, int lev)
{
	parent[u].first=from;
	level[u]=lev;
	
	int sizet=gp[u].size();
	for(int i=0;i<sizet;i++)
	{
		int v=gp[u][i].first;
		if(v==from) continue;
		parent[v].second=gp[u][i].second;
		dfs(u,v,lev+1);
	}
}

void lca_init(int n)
{

    memset(sp_table,-1,sizeof sp_table);
	memset(sp_cost,0,sizeof sp_cost);
    for(int i=0; i<=n; i++)
    {
        sp_table[i][0]=parent[i].first,sp_cost[i][0]=parent[i].second;
	}
    for(int i=1; 1<<i <=n; i++)
    {
        for(int j=0; j<=n; j++)
            if(sp_table[j][i-1]!=-1)
            {
                sp_table[j][i]=sp_table[sp_table[j][i-1]][i-1];
                sp_cost[j][i]=max(sp_cost[j][i-1],sp_cost[sp_table[j][i-1]][i-1]);
            }
    }


}

int lca_query(int p, int q)
{
    if(level[p]<level[q]) swap(p,q);

    int log=log2(level[p]);
    int mx=0;
	int i;
    for(i=log; i>=0; i--)
    {
        if(level[p]-(1<<i) >=level[q])
        {
            mx=max(mx,sp_cost[p][i]);
            p=sp_table[p][i];
        }
    }
    
    if(p==q) return mx;
	
    for(int i=log; i>=0; i--)
        if(sp_table[p][i]!=-1 && sp_table[p][i]!=sp_table[q][i])
        {
            mx=max(mx,max(sp_cost[p][i],sp_cost[q][i]));
            p=sp_table[p][i],q=sp_table[q][i];
        }
    mx=max(mx,max(sp_cost[p][0],sp_cost[q][0]));
    return mx;

}

int main()
{
	int x;
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		E.clear();
		R.clear();
		memset(gp,0,sizeof gp);
		memset(parent,0,sizeof parent);
		memset(level,0,sizeof level);
		
		int n,m,x,y,d,q,s,tt,ans=0;
		edge e;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&d);
			e.u=x;e.v=y;e.w=d;
			E.push_back(e);
		}
		kruskal(n);
		m=R.size();
		for(int i=0;i<m;i++)
		{
			gp[R[i].u].push_back(make_pair(R[i].v,R[i].w));
			gp[R[i].v].push_back(make_pair(R[i].u,R[i].w));
		}
		dfs(1,1,0);
		lca_init(n+1);
		printf("Case %d:\n",t);
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&s,&tt);
			ans=lca_query(s,tt);
			printf("%d\n",ans);
		}
	}
	return 0;
}
