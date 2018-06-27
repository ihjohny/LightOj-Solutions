//1129 - Consistency Checker 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
#define MX 100000000
int ans=0;
struct node
{
	bool endmark;
	node* next[10];
	node()
	{
		endmark=false;
		for(int i=0;i<10;i++)
		{
			next[i]=NULL;
		}
	}
}*root;
bool insert(char* str,int len)
{
	node* curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]==NULL)
		{
			curr->next[id]=new node();
		}
		if(curr->endmark==true)
		{
			return false;
		}
		curr=curr->next[id];
	}
	for(int i=0;i<10;i++)
	{
		if(curr->next[i]!=NULL)
				return false;
	}
	
	if(curr->endmark==true)
	{
		return false;
	}
	curr->endmark=true;
	return true;
}

void del(node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i])
            del(cur->next[i]);
            
	delete (cur);
}

int main()
{
	int x;
	int n,len;
	char number[15];
	scanf("%d",&x);
	for(int t=1;t<=x;t++)
	{
		root = new node();
		ans=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",number);
			len=strlen(number);
			if(!insert(number,len))
			{
				ans=0;
			}
		}
		if(ans)
		{
			printf("Case %d: YES\n",t);
		}
		else
		{
			printf("Case %d: NO\n",t);
		}
		
		del(root);
	}
	return 0;
}
