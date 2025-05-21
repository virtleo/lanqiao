#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,cot=1,a[10050],check[1000009];
void lesson1()
{ 
	cin>>n;
	for(int i=1;i<n+1;i++)cin>>a[i];
	for(int i=1;i<n+1;i++)
	{
		ll ans=0;
		for(int j=i;j<n+1;j++)
		{
			ans+=a[j];
			check[cot++]=ans;
//			cout<<check[cot-1]<<' ';
		}
	}
	sort(check,check+cot);
//	for(int i=0;i<n*(n-1)/2;i++)
//	{
//		cout<<check[i]<<" ";
//	}
	ll jieguo=1e12+1;
	for(int i=1;i<cot;i++)
	{
		jieguo=min(jieguo,check[i]-check[i-1]);
	}
	cout<<jieguo;
}
int main()
{
	lesson1();
	// 请在此输入您的代码
	return 0;
}
