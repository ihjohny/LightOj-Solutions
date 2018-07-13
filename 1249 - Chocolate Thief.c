	#include<stdio.h>
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int n,i;
            scanf("%d ",&n);
            int area[1000],person,thief,max=0,min=10000000;
            char str[1000][30];
            for(i=0;i<n;i++)
            {
                int l,w,h;
                scanf("%s %d %d %d",str[i],&l,&w,&h);  
                area[i]=(l*w*h);
            }
           
            for(i=0;i<n;i++)
            {
                if(area[i]<min)
                {
                    min=area[i];
                    person=i;
                }
                if(area[i]>max)
                {
                    max=area[i];
                    thief=i;
                }
            }
            if(!(min==max))
            {
                printf("Case %d: %s took chocolate from %s\n",t,str[thief],str[person]);
            }
            else
            {
                printf("Case %d: no thief\n",t);
            }
        }
        return 0;
    }
