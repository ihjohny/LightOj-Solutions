//Light oj 1303-ferris wheel
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        int n,m,key=0,count=0,time=0;
        vector<int>mqueue;
        int check[25][25],fw[25],completed[25];
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            mqueue.push_back(i);
            completed[i]=0;
            for(int j=0;j<m;j++)
            {
                check[i][j]=0;
                fw[j]=-1;
            }
        }
        while(count<n*m)
        {
            if(fw[key]!=-1)
            {
                check[fw[key]][key]=1;
                count++;
                if(++completed[fw[key]]!=m)
                {
                    mqueue.push_back(fw[key]);
                }
            }
            for(int i=0;i<mqueue.size();i++)
            {
                if(check[mqueue[i]][key]==0)
                {
                    fw[key]=mqueue[i];
                    mqueue.erase(mqueue.begin()+i);
                    break;
                }
                else
                {
                    fw[key]=-1;
                }
            }
            key=(key+1)%m;
            time=time+5;
        }
        printf("Case %d: %d\n",t,time);
    }
    return 0;
}