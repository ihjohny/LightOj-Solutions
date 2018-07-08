    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
        long long   int n,m,result=0;
            scanf("%lld",&n);
            scanf("%lld",&m);
            result=(m*n)/2;
           
            printf("Case %d: %lld\n",t,result);
        }
    return 0;
    }
