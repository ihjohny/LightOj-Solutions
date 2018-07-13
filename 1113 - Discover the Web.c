#include<stdio.h>
#include<string.h>
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        printf("Case %d:\n",t);
        char str[1000][100],command[100];
        strcpy(str[0],"http://www.lightoj.com/");
        int n,p;
        n=0;
        p=0;
        while(1)
        {
            scanf("%s",command);
            getchar();
            if(!strcmp(command,"QUIT"))
            {
                break;
            }
            else if(!strcmp(command,"VISIT"))
            {
               
                n++;
                p=n;
                scanf("%s",str[n]);
                getchar();
                printf("%s\n",str[n]);
            }
            else if(!strcmp(command,"BACK"))
            {
                n--;
                if(n<0)
                {
                    printf("Ignored\n");
                    n++;
                }
                else
                {
                    printf("%s\n",str[n]);
                }
            }
            else if(!strcmp(command,"FORWARD"))
            {
                n++;
                if(n>p)
                {
                    printf("Ignored\n");
                    n--;
                }
                else
                {
                    printf("%s\n",str[n]);
                }
            }
           
        }
    }
    return 0;
}
