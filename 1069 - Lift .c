#include<stdio.h>
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        int my,lift;
        scanf("%d%d",&my,&lift);
        printf("Case %d: ",t);
        int distance=0;
        if(lift>my)
        {
        distance=lift-my;
        }
        else if(my>lift)
        {
            distance=my-lift;
        }
        int lst;
        lst=distance*4;
       
        int myenter=3+5;
       
        int shftgroundt=my*4;
        int totaltime=lst+myenter+shftgroundt+5+3+3;
       
        printf("%d\n",totaltime);
    }
    return 0;
}