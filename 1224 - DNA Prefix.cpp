//1224 - DNA Prefix 
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
#define MX 100000000
int mx;
struct node
{
	int total;
	node* next[5];
	node()
	{
		total=1;
		for(int i=0;i<4;i++)
		{
			next[i]=NULL;
		}
	} 
}*root;

int insert(char* str,int len)
{
	node* curr=root;
	int sum=len;
	for(int i=0;i<len;i++)
	{
		int id;
		if(str[i]=='A')      id=0;
		else if(str[i]=='C') id=1;
		else if(str[i]=='G') id=2;
		else if(str[i]=='T') id=3;
		if(curr->next[id]==NULL)
		{
			curr->next[id]=new node();
			sum=len;
		}
		else
		{
			curr->next[id]->total=curr->next[id]->total+1;
			sum=(curr->next[id]->total)*(i+1);
			if(sum>mx) mx=sum;
		}
		curr=curr->next[id];
	}
	if(sum>mx) mx=sum;
	return mx;
}

void del(node* curr)
{
	for(int i=0;i<4;i++)
	{
		if(curr->next[i])
		{
			del(curr->next[i]);
		}
	}
	delete(curr);
}

int main()
{
	int x,t;
	scanf("%d",&x);
	for(t=1;t<=x;t++)
	{
		root=new node();
		int n,len,ans=0;
		mx=0;
		char str[55];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			len=strlen(str);
			ans=insert(str,len);
		}
		printf("Case %d: %d\n",t,ans);
		del(root);
	}
	return 0;
}
