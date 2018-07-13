    #include<stdio.h>
    #include<string.h>
     
    int main()
    {
        int x,t;
        scanf("%d ",&x);
        for(t=1;t<=x;t++)
        {
       
            char str0[1000],str1[1000];
            int len0,len1,i,j,strn0=0,strn1=0,same=0;
           
            gets(str0);
            gets(str1);
       
            for(i=0;(str0[i]!='\0');i++)
            {
                if(str0[i]!=' ')
                {
                    strn0++;
                    if((str0[i]>=65)&&(str0[i]<=90))
                    {
                        str0[i]=str0[i]+32;
                    }
                    for(j=0;str1[j]!='\0';j++)
                    {
                        if(str1[j]!=' ')
                        {
                            if((str1[j]>=65)&&(str1[j]<=90))
                            {
                                str1[j]=str1[j]+32;
                            }
                            if(str0[i]==str1[j])
                            {
                                same++;
                                str1[j]='0';
                                break;
                            }
                        }
                    }
                }
            }
            for(i=0;str1[i]!='\0';i++)
            {
                if(str1[i]!=' ')
                {
                    strn1++;
                }
            }
           
            if((strn0==same)&&(strn1==same))
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
