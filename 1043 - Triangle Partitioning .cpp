//1043 - Triangle Partitioning 
//By Undefined_Error
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int>
#define SZ 100005
#define MX 100000000


double getArea(double a, double b, double c) {
    double p = (a+b+c)/2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

double rationCal(double ab,double ac,double bc,double ad)
{
	double bigTri=getArea(ab,ac,bc);
	double smallTri=getArea(ad,((ac*ad)/ab),((bc*ad)/ab));
	return (smallTri/(bigTri-smallTri));	
}

int main()
{
	int n;
	double ab,ac,bc,r;
	double low,high,mid;
	scanf("%d",&n);
	for(int t=1;t<=n;t++)
	{
		scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&r);
		low=0;
		high=ab;
		for(int i=0;i<100;i++)
		{
			mid=(low+high)/2.0;
			if(rationCal(ab,ac,bc,mid) > r)
			{
				high=mid;
			}
			else
			{
				low=mid;
			}
		}
		
		printf("Case %d: ",t);
		cout<<setprecision(10)<<mid<<endl;
	}
    return 0;
}
