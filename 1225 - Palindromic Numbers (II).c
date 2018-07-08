    #include<stdio.h>
    #include<string.h>
    int main()
    {
        int x,t;
        scanf("%d ",&x);
        for(t=1;t<=x;t++)
        {
            char str[10000];
            gets(str);
            int i,j,count=0,len,temp;
            len=strlen(str);
           
            for(i=0,j=(len-1);i<(len/2);i++,j--)
            {
                if(str[i]==str[j])
                {
                    count++;
                }
            }
            if(count==i)
            {
                printf("Case %d: Yes\n",t);
            }
            else
            {
                printf("Case %d: No\n",t);
            }
     
        }  
    return 0;  
    }
