    #include <stdio.h>
    #include <math.h>
    const double EPS = 1e-9;
    int main()
        {
        int i,T;
        scanf("%d",&T);
        double r1,r2,r3,a,b,c,s,area,A,B,C,result;
        for(i =0; i<T; i++) {
                scanf("%lf%lf%lf",&r1,&r2,&r3);
                a = r1+r2;
                b = r2+r3;
                c = r3 + r1;
                s = (a+b+c)*0.5;
                area = sqrt(s*(s-a)*(s-b)*(s-c));
                A = acos((a*a+c*c-b*b)/(2.0*a*c));
                B = acos((a*a+b*b-c*c)/(2.0*a*b));
                C = acos((b*b+c*c-a*a)/(2.0*b*c));
                result = area-A*r1*r1*0.5-B*r2*r2*0.5-C*r3*r3*0.5;
                printf("Case %d: %.8lf\n",i+1,result+EPS);
                }
        return 0;
     
        }
