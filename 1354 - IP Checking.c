    #include<stdio.h>
    #include<math.h>
    int bin_to_dec(int);
    int main()
    {
        int x,y;
        scanf("%d",&y);
        for(x=1;x<=y;x++)
        {
            int a[4];
            int b[4];
            char c1,c2,c3;
            scanf("%d %c %d %c %d %c %d",&a[0],&c1,&a[1],&c2,&a[2],&c3,&a[3]);
            scanf("%d %c %d %c %d %c %d",&b[0],&c1,&b[1],&c2,&b[2],&c3,&b[3]);
            int i;
            for(i=0;i<4;i++)
            {
                if(a[i]!=(bin_to_dec(b[i])))
                {
                    break;
                }
            }
            if(i==4)
            {
                printf("Case %d: Yes\n",x);
            }
            else
            {
                printf("Case %d: No\n",x);
            }
        }
    return 0;  
    }
     
    int bin_to_dec(int a)
    {
        int n=0,p=0,d;
       
        while(1)
        {
            d=a%10;
            n=n+(d*pow(2,p));
            a=a/10;
            p++;
            if(p>8)
            {
                break;
            }
        }
        return n;
    }
