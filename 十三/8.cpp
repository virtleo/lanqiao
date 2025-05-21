#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
bool  check(ll a,ll b)
{
	return a>0&&a<=n&&b>0&&b<=m;
}
ll dx[]={0,1,0,-1,1,-1,-1,1};
ll dy[]={1,0,-1,0,1,-1,1,-1};
int main()
{

	cin>>n>>m;
	vector<vector<ll>>mp(n+1,vector<ll>(m+1,0));
	vector<vector<ll>>b(n+1,vector<ll>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j])
				b[i][j]=9;			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!mp[i][j])
			{
				for(int k=0;k<8;k++)
				{
					ll nx=i+dx[k],ny=j+dy[k];
					if(check(nx,ny))
					{
						if(b[nx][ny]==9)
							b[i][j]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
