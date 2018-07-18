//1337-The Crystal Maze
#include<bits/stdc++.h>
#define PII pair<int,int>
#define sz 505
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
    int x;
    scanf("%d",&x);
    for(int t=1;t<=x;t++)
    {
        char graph[sz][sz];
        int m,n,q;
        scanf("%d%d%d",&m,&n,&q);
        for(int y=1;y<=m;y++)
        {  
            getchar();
            for(int x=1;x<=n;x++)
            {
                scanf("%c",&graph[y][x]);
            }          
        }
        printf("Case %d:\n",t);
 
        int visited[sz][sz]={0,0};
        int ans[sz]={0};
        int g[sz][sz]={0};
        int flag=0;
       
        for(int u=0;u<q;u++)
        {
            int x,y;
            scanf("%d%d",&y,&x);
        //  cout<<" queue"<<graph[y][x]<<endl;
            if(!visited[y][x])
            {
            flag=flag+1;
            //cout<<query[u].first<<"  "<<query[u].second<<endl;
            //bfs
            //int visited[sz][sz]={0,0};
            queue<PII>q;
            visited[y][x]=1;
            g[y][x]=flag;
            q.push(PII(y,x));
            while(!q.empty())
            {
                PII top=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int a=top.first+dy[i];
                    int b=top.second+dx[i];
                    if(a>0&&b>0&&a<=m&&b<=n&&visited[a][b]!=1&&graph[a][b]!='#')
                    {
                        //cout<<"x "<<b<<" y "<<a<<endl;
                        if(graph[a][b]=='C')
                        {
                            ans[flag]++;
                        }
                        visited[a][b]=1;
                        g[a][b]=flag;
                        q.push(PII(a,b));
                    }
                }
            }
            //  cout<<" test "<<g[y][x]<<endl;
            }
           
                printf("%d\n",ans[g[y][x]]);
        }
    }
    return 0;
}