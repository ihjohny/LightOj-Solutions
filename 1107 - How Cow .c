    #include<stdio.h>
    int main()
    {
        int d,t;
        scanf("%d",&d);
        for(t=1;t<=d;t++)
        {
           
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int cow,i ;
            scanf("%d",&cow);
            printf("Case %d:\n",t);
            for(i=0;i<cow;i++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                if((x1<a&&a<x2)&&(y1<b&&b<y2))
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
            }
        }
    return 0;  
    }
