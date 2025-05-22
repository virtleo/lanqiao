#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int>>a(n,vector<int>(m,1));//n*m,³õÊ¼»¯Îª1 
	for(int i=0;i<q;i++)
	{
		int t,c;
		cin>>t>>c;
		if(t==0)
		{
			for(int j=0;j<m;j++)
			{
				a[c-1][j]=0;
			}
		}
		if(t==1)
		{
			for(int j=0;j<n;j++)
			{
				a[j][c-1]=0;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==1)
			{
				ans++;
			}
		}
	}
	int cnt=0;
	for(auto x:a)
	{
		cnt+=count(x.begin(),x.end(),1);
	}
	cout<<cnt<<'\n';
	cout<<ans;
	return 0;
 } 
