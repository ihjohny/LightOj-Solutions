    //1425 - The Monkey and the Oiled Bamboo
    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
        int t,x;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int n,i,dif,max,count;
            scanf("%d",&n);
           
            long long int arra[n+5];
            max=0;
            dif=0;
            count=0;
            arra[0]=0;
            for(i=1;i<=n;i++)
            {
                scanf("%lld",&arra[i]);
            }
           
            for(i=1;i<=n;i++)
            {
                dif=abs(arra[i]-arra[i-1]);
               
                if(dif==max)
                {
                    count=1;
                }
                if(dif>max)
                {
                    max=dif;
                    count=0;
                }
            }
            if(count==1)
            {
                max=max+1;
            }
            printf("Case %d: %d\n",t,max);
        }
        return 0;
    }
