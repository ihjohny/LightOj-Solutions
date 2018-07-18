    //1042 - Secret Origins
    #include<iostream>
    #include <stdio.h>
    #include <string.h>
    using namespace std;
     
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            long long int n,ans,mul;
            int i,j,u,ones,k;
            bool a[50],b[50];
           
        //  memset(a, 0, sizeof(a));
        //  memset(b, 0, sizeof(b));
           
            for(i=0;i<50;i++)
            {
                a[i]=0;
                b[i]=0;
            }
       
            k=0;
            ones=0;
            ans=0;
            mul=1;
            u=0;
            scanf("%lld",&n);
           
            while(n)
            {
                if(n%2==0)
                {
                    a[u]=0;
                }
                else
                {
                    a[u]=1;
                }
                n=n/2;
                u++;
            }
           
            i=0;
            j=1;
           
            while(1)
            {
                if((a[i]==1)&&(a[j]==0))
                {
                    break;
                }
                if(a[i]==1)
                {
                    ones++;
                }
               
                i++;
                j++;
            }                
           
            for(k=0;k<ones;k++)
            {
                b[k]=1;
            }
            b[j]=1;
           
            for(k=j+1;k<=u+1;k++)
            {
                b[k]=a[k];
            }
    /*     
            for(i=u+1;i>=0;i--)
            {
                printf("%d ",a[i]);
            }
            printf("\n");
            for(i=u+1;i>=0;i--)
            {
                printf("%d ",b[i]);
            }
    */     
            for(i=0;i<=u+1;i++,mul=mul*2)
            {
                ans+=b[i]*mul;
            }
            printf("Case %d: %lld\n",t,ans);
           
        }
       
        return 0;
    }
