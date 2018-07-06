    #include<stdio.h>
    //#include<stdlib.h>
    int main()
    {
        int i,b,n,array[50]={0};
       
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&b);
           
            if(b==0)
            {
                printf("0 0\n");
               
            }
            else if(b==20)
            {
                printf("10 10\n");
            }
           
            else if(b<11)
            {
                printf("%d %d\n",array[b],/*abs*/(b-array[b]));
                array[b]++;
            }
            else
            {
                int u;
                u=10-array[b];
                printf("%d %d\n",u,/*abs*/(b-u));
                array[b]++;
            }
        }
        return 0;
    }
