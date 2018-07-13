    #include<stdio.h>
    #include<math.h>
    #define PI acos(-1)
    int main()
    {
        int x,t;
        double R,n,r;
        double temp;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
           
            scanf("%lf%lf",&R,&n);
            temp=sin(PI/n);
            r=(R*temp)/(temp+1);
            printf("Case %d: %lf\n",t,r);
           
        }
        return 0;
    }
