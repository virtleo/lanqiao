#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int num,ans;
int a[maxn];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int j=1;j<=n;j++)
	{
		for (int i=1;i<=n;i++)
		{
			if(a[i]!=i)
			{
				swap(a[i],a[a[i]]);
				ans++;
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
}
