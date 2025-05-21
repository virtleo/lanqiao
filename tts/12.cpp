#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int lens(ll a)
{
	int len=0;
	while(a)
	{
		a/=10;
		len++;
	}
	return len;
}
int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	bool flag=false;
	for(ll i=a;i<=b;i++)
	{
		int len=n;
		int ji=0;
		while(i)
		{
			if(i%len!=0)
				break;
			i/=10;
			len--;
			ji++;
		}
		if(ji==n)
		{
			cout<<i<<'\n';
			flag=true;
		}
	}
	if(!flag)
	cout<<"No Solution";

	return 0;
 } 
