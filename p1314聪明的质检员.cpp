#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,s;
ll w[200005],v[200004];
void lesson1()
{
	cin>>n>>m>>s;
	for(int i=1;i<n+1;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<m+1;i++)
	{
		ll l,r;
		cin>>l>>r;
	}
}
int main()
{
	lesson1();
	return 0;
}
