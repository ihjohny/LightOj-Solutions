//1307 - Counting Triangles
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
//#define INF 99999999
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
int arra[2009]={0};
bool isTriangle(int a,int b,int c){
	if(a+b<=c || b+c<=a || c+a<=b)
		return false;
	else
		return true;
}

int binarySearch(int a,int b,int start,int end){
	if(start<=end){
		if(!isTriangle(a,b,arra[start]))
			return 0;
		if(isTriangle(a,b,arra[end]))
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
		int n,count;
		memset(arra,0,sizeof arra);
		count=0;
		sfint(n);
		forlp1(i,n){
			sfint(arra[i]);
		}
		sort(arra,arra+n+1);
		forlp1(j,n){
			forlpa(k,j+1,n){
					count+=binarySearch(arra[j],arra[k],k+1,n);
				}
			}
		printf("Case %d: %d\n",t,count);
	}
	return 0;
}
