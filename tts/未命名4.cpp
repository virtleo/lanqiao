#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll shu=0;
	while(n)
	{
		shu=n;
		n-=n&-n;

	}
	cout<<shu;
	return 0;
 } 
