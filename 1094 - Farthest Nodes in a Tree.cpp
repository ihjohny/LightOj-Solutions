//1094 - Farthest Nodes in a Tree
#include<bits/stdc++.h>
#define PI pair<int,int>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    for(int t=1;t<=x;t++)
    {
       
        vector<PI>graph[30005];
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(PI(v,w));
            graph[v].push_back(PI(u,w));
        }
   
        int maxx=0;
        int node=0;
        for(int i=0;i<=1;i++)
        {
            //BFS
            int visited[30005]={0};
            int distance[30005]={0};
            queue<PI>p;
            visited[node]=1;
            distance[node]=0;
            p.push(PI(node,0));
            while(!p.empty())
            {
                PI top=p.front();
                p.pop();
                for(int j=0;j<graph[top.first].size();j++)
                {
                    if(!visited[graph[top.first][j].first])
                    {
                        visited[graph[top.first][j].first]=1;
                        distance[graph[top.first][j].first]=distance[top.first]+graph[top.first][j].second;
                        p.push(graph[top.first][j]);
                    }
                }
               
                if(maxx<distance[top.first])
                {
                    maxx=distance[top.first];
                    node=top.first;
                }
            }
        }
       
        printf("Case %d: %d\n",t,maxx);
    }
    return 0;
}