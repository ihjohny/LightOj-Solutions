    #include<stdio.h>
    #include<math.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int n,i,ex=0;
            int count=0;
            scanf("%d",&n);
            int arra[n];
            int  add;
            arra[0]=2;
            for(i=1;i<=n;i++)
            {
                scanf("%d",&arra[i]);
               
     
            }
            for(i=0;i<n;i++)
            {
               
                if(arra[i+1]>arra[i])
                {  
                    double u=(arra[i+1]-arra[i]);
                    add=ceil(u/5);
            //      printf("add=%d\n",add);
                    count=count+add;
                }
            }
     
            printf("Case %d: %d\n",t,count);
        }
    return 0;
    }
