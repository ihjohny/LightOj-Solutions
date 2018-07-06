    #include<stdio.h>
    #include<string.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int as,os;
            scanf("%d",&as);
            scanf("%d",&os);
           
            int arra[as],i,j,u;
            for(i=0;i<as;i++)
            {
                scanf("%d",&arra[i]);
            }
           
            for(u=0;u<os;u++)
            {
                int d,temp,y,z;
                char ch;
               
                //getchar();
                scanf(" ");
                scanf("%c",&ch);
                if(ch=='S')
                {
                    scanf("%d",&d);
                    for(i=0;i<as;i++)
                    {
                        arra[i]=arra[i]+d;
                    }
                   
                }
                else if(ch=='M')
                {
                    scanf("%d",&d);
                    for(i=0;i<as;i++)
                    {
                        arra[i]=arra[i]*d;
                    }
                }
                else if(ch=='D')
                {
                    scanf("%d",&d);
                    for(i=0;i<as;i++)
                    {
                        arra[i]=arra[i]/d;
                    }
                }
                else if(ch=='R')
                {
                    for(i=0,j=as-1;i<as/2;i++,j--)
                    {
                        temp=arra[j];
                        arra[j]=arra[i];
                        arra[i]=temp;
                    }
                }
                else if(ch=='P')
                {
                    scanf("%d",&y);
                    scanf("%d",&z);
                    temp=arra[y];
                    arra[y]=arra[z];
                    arra[z]=temp;
                }
               
            }
           
            printf("Case %d:\n",t);
            for(i=0;i<as;i++)
            {
                if(i==as-1)
                {
                    printf("%d\n",arra[i]);
                }
                else
                {
                    printf("%d ",arra[i]);
                }
           
            }
        }
    return 0;  
    }
