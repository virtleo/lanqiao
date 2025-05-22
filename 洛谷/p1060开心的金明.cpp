#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>value(m+1,0);
	vector<int>p(m+1,0);
	vector<vector<long long>>f(m+1,vector<long long>(n+1,0));
	for(int i=1;i<=m;i++)
	{
		cin>>value[i]>>p[i];
	}
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j<value[i])
				f[i][j]=f[i-1][j];
			else 
				f[i][j]=max(f[i-1][j],f[i-1][j-value[i]]+value[i]*p[i]);
		}
	}
	cout<<f[m][n];
	return 0;
}
