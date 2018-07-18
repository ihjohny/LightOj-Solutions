//1174 - Commandos
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    for(int t=1;t<=x;t++)
    {
        vector<int>graph[1000];
        int N,R;
        scanf("%d%d",&N,&R);
        for(int i=0;i<R;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s,d;
        scanf("%d%d",&s,&d);
        //BFS
        int visited[1000]={0};
        int level[1000]={0};
        queue<int>p;
        visited[s]=1;
        level[s]=0;
        p.push(s);
        while(!p.empty())
        {
            int top=p.front();
            p.pop();
            for(int i=0;i<graph[top].size();i++)
            {
                if(!visited[graph[top][i]])
                {
                    visited[graph[top][i]]=1;
                    level[graph[top][i]]=level[top]+1;
                    p.push(graph[top][i]);
                }
            }
        }
       
        //BFS
        int visited2[1000]={0};
        int level2[1000]={0};
        queue<int>p2;
        visited2[d]=1;
        level2[d]=0;
        p2.push(d);
        while(!p2.empty())
        {
            int top=p2.front();
            p2.pop();
            for(int i=0;i<graph[top].size();i++)
            {
                if(!visited2[graph[top][i]])
                {
                    visited2[graph[top][i]]=1;
                    level2[graph[top][i]]=level2[top]+1;
                    p2.push(graph[top][i]);
                }
            }
        }
       
        int result=0;
        for(int i=0;i<N;i++)
        {
            int tmp=level[i]+level2[i];
            if(result<tmp)
            {
                result=tmp;
            }
        }
       
        printf("Case %d: %d\n",t,result);
       
    }
    return 0;
}