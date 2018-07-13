    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int m,n,test,dres,dreminder=0,dresult;
            scanf("%d%d",&m,&n);
            int res;
            if((m==1)||(n==1))
            {
                if(m>n)
                {
                    res=m;
                }
                else
                {
                    res=n;
                }
            }
            else if((m==2)||(n==2))
        /*  ((m==2)&&(n==2))||
            ((m==2)&&(n==3))||
            ((m==3)&&(n==2))
        */
            {
                if(n==2)
                {
                    test=m;
                }
                else
                {
                    test=n;
                }
               
                dresult=test/2;            
                dres=(dresult+1)/2;
                if(dresult%2==0)
                {
                    dreminder=(test%2);
                }
                res=(dres*4)+(dreminder*2);
            }
            else
            {
                if((n*m)&1)
                {
                    //odd
                    res=((m*n)/2)+1;
                }
                else
                {
                    //even
                    res=((m*n)/2);
                }
            }
            printf("Case %d: %d\n",t,res);
        }
        return 0;
    }
