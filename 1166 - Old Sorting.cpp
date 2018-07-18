//Lightoj 1166
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
 
int main()
{
    int n,t;
    scanf("%d",&n);
    for(t=1;t<=n;t++)
    {
        int x,arra[100000],i,j,temp,m,count=0,min;
        scanf("%d",&x);
        for(i=0;i<x;i++)
        {
            scanf("%d",&arra[i]);
        }
       
        for(j=0;j<x;j++)
        {
            min=arra[j];
            m=j;
            for(i=j;i<x;i++)
            {
                if(arra[i]<min)
                {
                    min=arra[i];
                    m=i;
                }
            }
           
            if(arra[j]!=arra[m])
            {
                temp=arra[j];
                arra[j]=arra[m];
                arra[m]=temp;
                count++;
            }  
        }
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}