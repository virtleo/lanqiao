#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	cin>>n>>m;
	priority_queue<ll,vector<ll>,greater<ll>>q;
	vector<int>a(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());

//	for(auto x:a)
//	{
//		cout<<x<<' ';
//	}
	for(int i=0;i+m-1<n;i++)
	{
		ll l=0;

		l+=abs(pow(a[i+m-1],2)-pow(a[i],2)); 

		q.push(l);
	}
	cout<<q.top();
	return 0;
 } 
