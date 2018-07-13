    #include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
           
            int n,m,k;
            scanf("%d%d%d",&n,&m,&k);
            int arra[100][100];
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<k;j++)
                {
                    scanf("%d",&arra[i][j]);
                }
            }
            int p;
            scanf("%d",&p);
            int q[100];
            for(i=0;i<p;i++)
            {
                scanf("%d",&q[i]);
            }
     
            int u,test,istrue[100]={0},c4=0,total=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<k;j++)
                {
                    test=arra[i][j];
                    for(u=0;u<p;u++)
                    {
                        if(test==q[u])
                        {
                            istrue[i]=1;
                            goto label;
                        }
                        if((test<0)&&(test==(-1*q[u])))
                        {
                            c4=1;
                        }
                    }
                    if((test<0)&&c4==0)
                    {
                        istrue[i]=1;
                   
                        goto label;
                    }
                    c4=0;
                }
                label:
                {
                    total=total+istrue[i];
                }
            }
            if(total==n)
            {
                printf("Case %d: Yes\n",t);
            }
            else
            {
                printf("Case %d: No\n",t);
            }
        }
        return 0;
    }
