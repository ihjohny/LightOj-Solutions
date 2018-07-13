#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        double r1,r2,h,p,R,result;
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        R=r2+((r1-r2)*p)/h;
       
        result=(1/3.0)*p*PI*(R*R+R*r2+r2*r2);
        printf("Case %d: %lf\n",t,result);
    }
    return 0;
}
