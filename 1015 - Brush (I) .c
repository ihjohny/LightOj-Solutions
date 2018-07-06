    #include<stdio.h>
    int main()
    {
        int f,i;
        scanf("%d",&f);
        for(i=1;i<=f;i++)
        {
     
            int n,t,arra[10000],sum=0;
            scanf("%d",&n);
            for(t=0;t<n;t++)
            {
                scanf("%d",&arra[t]);
                if(arra[t]>0)
                {
                    sum=sum+arra[t];
                }
            }
            printf("Case %d: %d\n",i,sum);
           
        }
        return 0;
    }
