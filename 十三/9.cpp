#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mo=1e9+7;
int n,m;
ll f[110][110][110];//dp
//i,j,k分别为 n,m,k
int main()
{
	cin>>n>>m;//n为店，m为花 
	f[0][0][2]=1; 
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(i&&k%2==0)f[i][j][k]=(f[i][j][k]+f[i-1][j][k/2])%mo;
				if(j&&k)f[i][j][k]=(f[i][j][k]+f[i][j-1][k+1])%mo;
			}
		}

	}
	cout<<f[n][m-1][1];
	return 0;
}
