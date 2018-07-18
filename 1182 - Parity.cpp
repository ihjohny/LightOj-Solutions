#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x,t;
    scanf("%lld",&x);
    for(int t=1;t<=x;t++)
    {
        long long int n,count=0;
        scanf("%lld",&n);
        while(n>0)
        {
            if(n%2==1||n==1)
            {
                count++;
            }
            n=n/2;
        }
       
        if(count%2==0)
        {
            printf("Case %d: even\n",t);
        }
        else
        {
            printf("Case %d: odd\n",t);
        }
    }
    return 0;
}