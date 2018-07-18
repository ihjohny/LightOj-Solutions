//1111 - Best Picnic Ever
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1005];
int mp[1005];
int visited[1005];
void dfs(int s)
{
   // cout<<"  "<<s;
    visited[s]=1;
    mp[s]++;
    for(int i=0;i<graph[s].size();i++)
    {
        if(!visited[graph[s][i]])
        {
            dfs(graph[s][i]);
        }
    }
}
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        for(int g=0;g<1005;g++)
        {
            mp[g]=0;
            graph[g].clear();
        }
        int k,n,m,u,v,ans=0;
        int people[105];
        scanf("%d%d%d",&k,&n,&m);
        for(int i=0;i<k;i++)
            scanf("%d",&people[i]);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        for(int i=0;i<k;i++)
        {
            for(int h=0;h<1005;h++)
            {
                visited[h]=0;
            }
     //       cout<<"dfs ";
            dfs(people[i]);
        }
        for(int i=0;i<=n;i++)
        {
            if(mp[i]>=k)
                    ans++;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}