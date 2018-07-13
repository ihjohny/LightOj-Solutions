#include<stdio.h>
#include<string.h>
int main()
{
    int x,y;
    scanf("%d",&y);
    getchar();
    for(x=1;x<=y;x++)
    {
   
       long long int  b,rem,mul,i,n,yes;
       char a[1000];
       mul=0;
       rem=0;
       yes=0;
       memset(a,'\0',sizeof(a));
       //in=0;
       scanf("%s",a);
       scanf("%lld",&b);
       n=strlen(a);
       if(b<0)
       {
        b=b*(-1);
       }
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-')
            {
                continue;
            }
            mul=mul+(a[i]-'0');
            rem=mul%b;
            mul=rem*10;
            if((rem==0)&&i==(n-1))
            {
                yes=1;
                printf("Case %d: divisible\n",x);
            }
             
        }
        if(yes==0)
        {
            printf("Case %d: not divisible\n",x);
        }
    }
    return 0;
}
