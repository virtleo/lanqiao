#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int dfs(int pos,int s,vector<int>&a,vector<vector<int>>&dp);
int main()
{

	cin>>n>>m;
	vector<int> a(n+2,0);
	vector<vector<int>>dp(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	

	vector<vector<int>>f(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j<a[i])
			{
				f[i][j]=f[i-1][j];	
			}
			else if(j>a[i]) 
			{
				f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
			}
			else 
			{//如果第i道菜正好花光j，加一 
				f[i][j]=f[i-1][j]+1;
				}	
		}	
	}
	cout<<f[n][m];
	//cout<<dfs(1,0,a,dp);
	return 0;
}
int dfs(int pos,int s,vector<int>&a,vector<vector<int>>&dp)
{
	int ans=0; 
	if(s==m)return 1;
	else if(s>m)return 0;
	if(dp[pos][s])return dp[pos][s];
	for(int i=pos;i<=n;i++)
	{
		ans+=dfs(i+1,s+a[i],a,dp);
	}
	return dp[pos][s]=ans;
	
}

