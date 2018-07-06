    #include<stdio.h>
    #include<math.h>
    int main()
    {
        long i,j;
        double pi= 2*acos(0.0);
       
        scanf("%d",&j);
        for(i=1;i<=j;i++)
        {
           
                double r,result;
            scanf("%lf",&r);
            result=(pow(2*r,2)-(pi*r*r))+(10e-9);
            printf("Case %d: %.2lf\n",i,result);
           
        }
        return 0;
    }
