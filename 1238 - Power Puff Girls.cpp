//1238 power puff girls
#include<bits/stdc++.h>
#define PI pair<int,int>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    for(int t=1;t<=x;t++)
    {
        char graph[50][50];
        int m,n;
        char ch;
        int ax,ay,bx,by,cx,cy,hx,hy;
        scanf("%d%d",&m,&n); //m row //n column
        for(int y=0;y<m;y++)
        {
            getchar();
            for(int x=0;x<n;x++)
            {
                scanf("%c",&ch);
                graph[y][x]=ch;
                if(ch=='a')
                {
                    ax=x;
                    ay=y;
                }
                else if(ch=='b')
                {
                    bx=x;
                    by=y;
                }
                else if(ch=='c')
                {
                    cx=x;
                    cy=y;
                }
                else if(ch=='h')
                {
                    hx=x;
                    hy=y;
                }
            }
        }
    /*  //input check
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",graph[i][j]);
            }
            cout<<endl;
        }
    */ 
        //BFS
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int visited[50][50]={0,0};
        int dist[50][50]={0,0};
       
        queue<PI>q;
        visited[hy][hx]=1;
        dist[hy][hx]=0;
        q.push(PI(hy,hx));
        while(!q.empty())
        {
            PI top=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int a=top.first+dy[i];
                int b=top.second+dx[i];
                if( a>=0 && b>=0 && a<m && b<n && visited[a][b]!=1
                    && graph[a][b]!='#' && graph[a][b]!='m')
                    {
                        visited[a][b]=1;
                        dist[a][b]=dist[top.first][top.second]+1;
                        q.push(PI(a,b));
                    }
            }
        }
       
        //printf("dist a = %d\n",dist[ay][ax]);
        //printf("dist b = %d\n",dist[by][bx]);
        //printf("dist c = %d\n",dist[cy][cx]);
        int maxx=max(dist[ay][ax],dist[by][bx]);
        int ans=max(maxx,dist[cy][cx]);
        printf("Case %d: %d\n",t,ans);
       
    }
    return 0;
}