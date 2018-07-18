    //LOJ1016
    #include<iostream>
    #include<algorithm>
    #include<stdio.h>
    using namespace std;
     
    int main()
    {
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
            int n,w,i,j,count=1;
            long long int x,y[50005];
            scanf("%d%d",&n,&w);
            for(i=0;i<n;i++)
            {
                scanf("%lld%lld",&x,&y[i]);
            }
            sort(y,y+n);
        /// cout<<"first "<<y[0]<<endl;
        /// cout<<"last "<<y[n-1]<<endl;
            i=y[0];
            j=0;
            while(i<(y[n-1]))
            {
     
                i=i+w;
                ///cout<<"i "<<i<<endl;
                for(;j<n;j++)
                {
                    if((y[j])>i)
                    {
                        count++;
                ///     cout<<"count "<<count<<endl;
                        i=(y[j]);
                        break;
                    }
                }
            }
            printf("Case %d: %d\n",t,count);
     
        }
        return 0;
    }
