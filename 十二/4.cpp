#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void lesson1()
{
	ll ans=0;
	ll shu=1;
	ll a[10020];
	ll n=2021041820210418;
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			a[shu++]=i;
			if(i*i!=n)
				a[shu++]=n/i;
		}

	}
	for(ll i=1;i<=shu;i++)
	{
		for(ll j=1;j<=shu;j++)
		{
			for(ll k=1;k<=shu;k++)
			{
				if(a[i]*a[j]*a[k]==n)
				{
					ans++;
					//cout<<ans<<' ';
				}
					
			}
		}
	}
	cout<<ans;
}
int main()
{
	lesson1();
	return 0;
 } 
