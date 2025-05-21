#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>a(n+10,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<m;i++)
	{
		int liex;
		cin>>liex;
		if(liex==1)
		{
	
		}
		else if (liex==2)
		{
			for(int i=0;i<n;i++)
			{
				if((a[i]+a[i+1])%2==0)
				{
					a[i].push_buck((a[i]+a[i+1])/2);
				}
			}
		}
		else {
			reverse(a+l-1,a+r-1);
		}
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<' ';
	return 0;
 } 
