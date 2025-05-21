#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	bool flag=false;
	ll m,kl;
	for(ll i=1;i<sqrt(sqrt(n));i++)
	{
		ll shu=1;
		ll k=i;
		ll jieguo=0;
		while(jieguo<n)
		{
			jieguo+=pow(shu,k);
			shu++;
		}
		if(jieguo==n)
		{
			flag=true;
			m=shu;
			kl=k;
		}
	}
	if(flag)
	{
		string s;
		for(int i=1;i<m;i++)
		{
			s+=to_string(i)+"^"+to_string(kl)+"+"; 
		}
		s.pop_back();
		cout<<s;
	}
	else 
	{
		printf("Impossible for %lld.",n);
	}
	return 0;
 } 
