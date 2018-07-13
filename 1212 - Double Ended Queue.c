#include<stdio.h>
#include<string.h>
#include<deque>
//#include<stack>
//#include<iostream>
//#include<queue>
using namespace std;
int main()
{
    int x,t;
    scanf("%d",&x);
    for(t=1;t<=x;t++)
    {
        printf("Case %d:\n",t);
        int i,n,m;
        int number;
        deque<int>q;
        char command[20];      
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%s",command);
            if(!strcmp(command,"pushLeft"))
            {
                scanf("%d",&number);
                if(q.size()!=n)
                {
                    q.push_front(number);
                    printf("Pushed in left: %d\n",number);
                }
                else
                {
                    printf("The queue is full\n");
                }
            }
            else if(!strcmp(command,"pushRight"))
            {
                scanf("%d",&number);
                if(q.size()!=n)
                {
                    q.push_back(number);
                    printf("Pushed in right: %d\n",number);
                }
                else
                {
                    printf("The queue is full\n");
                }
            }
            else if(!strcmp(command,"popLeft"))
            {
                if(!q.empty())
                {
                    printf("Popped from left: %d\n",q.front());
                    q.pop_front();
                }
                else
                {
                    printf("The queue is empty\n");
                }
            }
            else if(!strcmp(command,"popRight"))
            {
                if(!q.empty())
                {
                    printf("Popped from right: %d\n",q.back());
                    q.pop_back();
                }
                else
                {
                    printf("The queue is empty\n");
                }
            }
        }
    }
    return 0;
}
