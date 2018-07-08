    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int n,count=0;
            scanf("%d",&n);
           
            while(n>0)
            {
                if(n%2==1||n==1)
                {
                    count++;
                }
                n=n/2;
            }
           
            if(count%2==0)
            {
                printf("Case %d: even\n",t);
            }
            else
            {
                printf("Case %d: odd\n",t);
            }
        }
    return 0;  
    }
