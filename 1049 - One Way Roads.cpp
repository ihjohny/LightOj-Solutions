//1049 - One Way Roads
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,t;
    scanf("%d",&x);
    for(int t=1;t<=x;t++)
    {
        vector<int>list[105];
        int graph[105][105]={0};
        int n,totalsum=0,source=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(!source)
                source=u;
           
            graph[u][v]=w;
            totalsum=totalsum+w;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        //
        int sum=0;
        int visited[105]={0};
        queue<int>q;
        q.push(source);
        visited[source]=1;
        while(!q.empty())
        {
            int top=q.front();
                    q.pop();
        //  cout<<top<<" ";
            for(int i=0;i<list[top].size();i++)
            {
                if(!visited[list[top][i]])
                    {
                        visited[list[top][i]]=1;
                        if(graph[top][list[top][i]])
                        {
                            sum=sum+graph[top][list[top][i]];
                        }
                        q.push(list[top][i]);
                        break;
                        //cout<<" "<<list[top][i]<<" ";
                    }
            }
        }
        sum=sum+graph[list[source][1]][source];
        //printf("sum = %d \ntotal sum = %d \n",sum,totalsum);
        printf("Case %d: %d\n",t,min(sum,totalsum-sum));
    }
    return 0;
}