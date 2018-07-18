//1009 - Back to Underworld
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        vector<int>graph[200005];
        vector<int>nodes;
        int edge,u,v,j;
       
        scanf("%d",&edge);
        for(j=0;j<edge;j++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            nodes.push_back(u);
            nodes.push_back(v);
        }
        int visited[200005]={0};
        int color[200005]={0};
        int one=0,mone=0,ans=0;
        int sz=nodes.size();
        for(int i=0;i<sz;i++)
        {
            if(!visited[nodes[i]])
            {
                mone=1;
                one=0;
                int source=nodes[i];
                color[source]=-1;
                visited[source]=1;
                queue<int>q;
                q.push(source);
                while(!q.empty())
                {
                    int top=q.front();
                    q.pop();
                    int y;
                    int siz=graph[top].size();
                    for(y=0;y<siz;y++)
                    {
                        if(visited[graph[top][y]]==0)
                        {
                            if(color[top]==-1)
                            {
                                color[graph[top][y]]=1;
                                one++;
                            }
                            else
                            {
                                color[graph[top][y]]=-1;
                                mone++;
                            }
 
                            visited[graph[top][y]]=1;
                            q.push(graph[top][y]);
                        }
                    }
                }
               
                if(one>mone)
                {
                    ans=ans+one;
                }
                else
                {
                    ans=ans+mone;
                }
               
            }
                   
        }
        printf("Case %d: %d\n",t,ans);
               
    }
    return 0;
}