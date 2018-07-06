    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            long long int w,n,m;
            scanf("%lld",&w);
           
            if(w%2!=0)
            {
                printf("Case %d: ",t);
                printf("Impossible\n");
            }
            else
            {
                for(n=2;n<=w;n=n+2)
                {
                        m=w/n;
                        if(m%2==1&&(m*n)==w)
                        {
                        printf("Case %d: ",t);
                        printf("%lld %lld\n",m,n);
                        break;
                        }
                }
               
            }
        }
    return 0;  
    }
