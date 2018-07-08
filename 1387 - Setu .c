    #include<stdio.h>
    #include<string.h>
    int main()
    {
        int x,y;
        scanf("%d",&x);
        for(y=1;y<=x;y++)
        {
            int n,s,sum=0;
            int i;
            char de[100];
           
            scanf("%d",&n);
            printf("Case %d:\n",y);
            for(i=0;i<n;i++)
            {
                scanf("%s",&de);
                if(!strcmp(de,"donate"))
                {
                    scanf("%d",&s);
                    sum=sum+s;
                }
                else
                {
                    printf("%d\n",sum);
                }
            }
        }
        return 0;
       
    }
