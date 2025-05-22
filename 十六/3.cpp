#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,a,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a!=1)
		{
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
 } 
