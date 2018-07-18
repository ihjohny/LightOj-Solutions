//1012 - Guilty Prince
#include<bits/stdc++.h>
#define PI pair<int,int>
using namespace std;
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        int graph[50][50]={0};
        int x,y,sx,sy; //y=row  x=col
        char ch;
        scanf("%d%d",&x,&y);
        getchar();
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                scanf("%c",&ch);
                if(ch=='#')
                {
                    graph[i][j]=-1;
                }
                else if(ch=='@')
                {
                    sx=j;
                    sy=i;
                }
            }
            getchar();
           
        }
        int tx,ty,ans=1;
        int visited[50][50]={0};
        int fx[4]={1,-1,0,0};
        int fy[4]={0,0,1,-1};
        //BFS
        queue<PI>q;
        visited[sy][sx]=1;
        q.push(PI(sx,sy));
        while(!q.empty())
        {
            PI top=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                tx=top.first+fx[k];
                ty=top.second+fy[k];
                if(tx>=0&&ty>=0&&tx<x&&ty<y&&visited[ty][tx]==0&&graph[ty][tx]!=-1)
                {
                    visited[ty][tx]=1;
                    ans++;
                    q.push(PI(tx,ty));
                }
            }
        }
       
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}