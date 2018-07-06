#include<stdio.h>
#include<math.h>
int main()
{
    int long long bn,bnn,s,n,a,b,i,m;
    int long long res1,result,mul;
    int cases=1;
        scanf("%d",&m);
        for(i=0;i<m;i++)
    {
       
   
    scanf("%lld",&n);
    result=sqrt(n);
    mul=(result)*(result);
    s=(result*2)+1;
    bn=n-(result*result);
    res1=result+1;
   
    if(n==1)
    {
        a=1;
        b=1;
    }
    else{
   
        if(mul==n)
        {
            if(result%2==0)
            {
                a=result;
                b=(result*result)-n+1;
            }
            else
            {
                a=(result*result)-n+1;
                b=result;
            }
           
            }  
        else
            {
           
                if(res1%2==0)
                {
                    if(s/2>=bn)
                    {  
                       
                        a=bn;
                        b=res1;
           
                    }
                    else
                    {
                        a=res1;
                        bnn=(res1*res1)-n+1;
                        b=bnn;
                    }
                   
                   
                }
                else
                {
                    if(s/2>=bn)
                    {  
                        a=res1;
                        b=bn;
           
           
                    }
                    else
                    {
                        bnn=(res1*res1)-n+1;
                        a=bnn;
                        b=res1;
                    }
                }
            }
   
    }
   
    printf("Case %d: %d %d\n",cases++,a,b);
}
   
    return 0;
}