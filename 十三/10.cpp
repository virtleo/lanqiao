#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
//typedef pair<ll,int> pii;
//priority_queue<pii,vector<pii>,less<pii>>q;
const ll mmm=2e6+100;
ll h[mmm][8];
ll ans=0;
int n;
ll heig(ll a)
{
	return sqrtl(a/2+1);
}
void lesson1()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i][0];
		for(int j=1;1<h[i][j-1];j++)
		{
			h[i][j]=heig(h[i][j-1]);
			ans++;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;h[i][j]!=1;j++)
		{
			for(int k=0;h[i+1][k]!=1;k++)
			{
				if(h[i][j]==h[i+1][k])
				{
					ans--;
					break;
				}
			}
		}
	}
	cout<<ans;
}
int main()
{	
	lesson1();
	return 0;
 } 
