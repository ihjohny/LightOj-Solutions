    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            long long int r1,c1,r2,c2,j1=0,j2=0;
            scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
            printf("Case %d: ",t);
            if((((c1%2==0&&r1%2==0)||(c1%2==1&&r1%2==1))&&((c2%2==0&&r2%2==1)||(c2%2==1&&r2%2==0)))||
    (((c2%2==0&&r2%2==0)||(c2%2==1&&r2%2==1))&&((c1%2==0&&r1%2==1)||(c1%2==1&&r1%2==0))))  
            {
                printf("impossible\n");
            }
            //
            else
            {
                if(c1>c2)
                {
                    j1=c1-c2;
                }
                else
                {
                    j1=c2-c1;
                }
               
                if(r1>r2)
                {
                    j2=r1-r2;
                }
                else
                {
                    j2=r2-r1;
                }
               
                if(j1==j2)
                {
                    printf("%d\n",1);
                }
                else
                {
                    printf("%d\n",2);
                }
            }
        }
    return 0;  
    }
