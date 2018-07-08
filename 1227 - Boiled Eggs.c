    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int n,p,q,count=0;
            scanf("%d%d%d",&n,&p,&q);
            int i,arra[1000],wight=0;
            for(i=0;i<n;i++)
            {
                scanf("%d",&arra[i]);
            }
       
            for(i=0;(i<p&&i<n);i++)
            {
               
                wight=wight+arra[i];
                if(wight>q)
                {
                    break;
                }
                count++;
            }
            printf("Case %d: %d\n",t,count);
        }
    return 0;
    }
