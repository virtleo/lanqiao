#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100],b[100];
ll fz=0,fm=1;
ll gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld/%lld",&a[i],&b[i]);
		fm=fm/gcd(fm,b[i])*b[i];
	}
	ll fz=0;
	for(int i=0;i<n;i++)
	{
		fz+=fm/b[i]*a[i];
	}
	ll t=gcd(fm,abs(fz));
	fz=fz/t;
	fm=fm/t;
	if(fz%fm==0)
	{
		cout<<fz/fm;
	}
	else if(fz>fm)
	{
		cout<<fz/fm<<' '<<fz%fm<<'/'<<fm;
	}
	else 
	{
		cout<<fz%fm<<'/'<<fm;
	}
	return 0;
 } 
