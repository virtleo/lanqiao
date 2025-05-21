#include<iostream>
#include<vector> 
using namespace std;
int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	vector<vector<int>>arr(n+1,vector<int>(m+1,0));
	vector<vector<int>>s(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+arr[i][j];
		}
	}
	int mx=-1e9;
	int x,y;
	for(int i=1;i<=n-c+1;i++)
	{
		for(int j=1;j<=m-c+1;j++)
		{
			int sum=s[i+c-1][j+c-1]-s[i+c-1][j-1]-s[i-1][j+c-1]+s[i-1][j-1];
			if(sum>mx)
			{
				mx=sum;
				x=i;
				y=j;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
 } 
