    #include<stdio.h>
    #include<string.h>
    int main()
    {
        int day1,year1,day2,year2;
        char mon1[100],mon2[100];
        char ch1,ch2;
       
        int x,t;
        scanf("%d",&x);
        for(t=1;t<=x;t++)
        {
        int leap=0;
        scanf("%s",mon1);
        scanf("%d %c",&day1,&ch1);
        scanf("%d ",&year1);
       
        scanf("%s",mon2);
        scanf("%d %c",&day2,&ch2);
        scanf("%d",&year2);
       
        if(year1==year2)
        {
           
            if((monthtest(mon1)==1))
            {
                if((monthtest(mon2)==0)||((strcmp(mon2,"February")==0)&&day2==29))
                {
                    if(year1%400==0)
                    {
                        leap=1;
                    }
                    else if((year1%4==0)&&(year1%100!=0))
                    {
                        leap=1;
                    }
                }
            }
        }
           
        else
        {
     
       
        if(monthtest(mon1)==0)
        {
            year1=year1+1;
        }
       
        if(monthtest(mon2))
        {
            if((strcmp(mon2,"February")==0)&&day2==29)
            {
                year2=year2;
            }
            else
            {
                year2=year2-1;
            }
           
        }
       
        year1=year1-1;
        //year2=year2-1;
       
        leap=(year2/4-year2/100+year2/400)-(year1/4-year1/100+year1/400);
        }
        printf("Case %d: %d\n",t,leap);
        }
    return 0;
    }
     
    int monthtest(char mon1[])
    {
        char test[10]={"January"},test1[10]={"February"};
        if((strcmp(mon1,test)==0)||(strcmp(mon1,test1))==0)
        {
            return 1;
        }
        else
        {
          return 0;
        }
    }
