#include<stdio.h>
#include<math.h>
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        double r,ab,s,ox,oy,ax,ay,bx,by,alpha,result;
        scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
       
        r=sqrt(((ax-ox)*(ax-ox))+((ay-oy)*(ay-oy)));
        ab=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
       
        result=((2*r*r)-(ab*ab))/(2*(r*r));
        alpha=acos(result);
        result=r*alpha;
        printf("Case %d: %lf\n",t,result); 
    }
    return 0;
}
