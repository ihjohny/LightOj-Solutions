#include<bits/stdc++.h>
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        int a,b,c,f,s;
        scanf("%d%d%d",&a,&b,&c);
        int xyz;
    printf("Case %d: ",t); 
            if(a>c&&a>b)
            {
                xyz=a;
                f=b;
                s=c;
            }
            else if(b>a&&b>c)
            {
                xyz=b;
                f=a;
                s=c;
            }
            else if(c>a&&c>b)
            {
                xyz=c;
                f=a;
                s=b;
            }
        if(pow(xyz,2)==((pow(f,2))+(pow(s,2))))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
return 0;
}