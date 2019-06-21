//1088 - Points in Segments
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<28
#define ll long long
#define SZ 100009
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define forlpa(i,a,n) for(int i=a;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int,int> PII;
#define SIZE 100005
//#define INF 99999999
int points[SIZE];
int binarySearch(int a,int b,int start,int end){
	if(end>=start){
		if(points[start]>b || points[end]<a)
			return 0;
		if( points[start] >=a && points[end]<=b)
		{
			return (end-start+1);
		}
		int mid=(start+end)/2;	
		int t1=binarySearch(a,b,start,mid);
		int t2=binarySearch(a,b,mid+1,end);
		return t1+t2;
	}
	else
		return 0;
}
int main()
{
	int testCase;
	sfint(testCase);
	forlp1(t,testCase){
		int n,q,a,b;;
		memset(points,0,sizeof points);
		sfint2(n,q);
		forlp1(i,n){ sfint(points[i]);}
		printf("Case %d:\n",t);
		forlp1(i,q){
			sfint2(a,b);
			int result=binarySearch(a,b,1,n);
			printf("%d\n",result);
		}
	}
    return 0;
}
