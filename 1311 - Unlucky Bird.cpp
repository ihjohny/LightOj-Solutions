    #include<iostream>
    #include<stdio.h>
    #include<math.h>
    using namespace std;
    //using namespace std;
    int main()
    {
        int x,y;
        scanf("%d",&x);
        for(y=1;y<=x;y++)
        {
            double v1,v2,v3,a1,a2;
            scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
            double t,t1,t2,d1,d2,d;
            t=v1/a1;
            t1=v1/a1;
            t2=v2/a2;
     
     
            t = max(t1,t2);
     
            d1=(v1*t1)-(.5*a1*pow(t1,2));
            d2=(v2*t2)-(.5*a2*pow(t2,2));
            d=d1+d2;
            printf("Case %d: %.8lf %.8lf\n",y,d,t*v3);
        }
    return 0;  
    }
