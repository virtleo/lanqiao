#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int n;
double l,r;
const double eps=1e-6;
double f(double t);
vector<double>k(12+3,0);
int main()
{

	cin>>n;
	cin>>l;
	cin>>r;

	for(int i=0;i<n+1;i++)
	{
		cin>>k[i];
	}
	while(r-l>1e-8)
	{
//		double mid =(l+r)/2;
//		if(f(mid+eps)>f(mid-eps)) l =mid;
//		else r=mid;
		double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if (f(lmid)<f(rmid)) l=lmid;
		else r=rmid;
	}
	cout<<endl;
	cout<<fixed<<setprecision(5)<<r<<"\n";
	//printf("%.5f",r);
	return 0;
 }
double f(double t)
{
	double ans=0;
	for(int i=0;i<n+1;i++)
	{
		(ans*=t)+=k[i];
	}
	return ans;
}

