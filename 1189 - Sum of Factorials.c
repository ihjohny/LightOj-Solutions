#include<stdio.h>
 
int main()
{
   
    unsigned long long fact[22];
    int i;
    fact[0]=1;
    for(i=1;i<=20;i++)
    {
        fact[i]=fact[i-1]*i;
    }
   
    int tt,x;
    scanf("%d",&x);
    for(tt=1;tt<=x;tt++)
    {
       
    long long t,n;
    int i,k,arra[1000],u,g,possible;
    t=0;
    i=0;
    u=0;
    g=0;
    possible=0;
   
    scanf("%lld",&n);
    printf("Case %d: ",tt);
   
    while(1)
    {
   
        if(fact[i+1]>n||g==1)
        {
            t=t+fact[i];
            if(t<=n)
            {
                arra[u]=i;
                u++;
                if(t==n)
                {
                    possible=1;
                    break;
                }  
            }
            else
            {
                t=t-fact[i];
            }
            g=1;
        }
        if(g==1)
        {
            i--;
        }
        else
        {
            i++;
        }
        if(i<0)
        {
            break;
        }
    }
   
   
    if(possible==1)
    {
        for(i=u-1;i>=0;i--)
        {
            if(i==0)
            printf("%d!\n",arra[i]);
            else
            printf("%d!+",arra[i]);
        }
    }
    else
    {
        printf("impossible\n");
    }
    }      
    return 0;
}
