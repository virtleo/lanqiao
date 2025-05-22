#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mo=1e9+7;
void lesson1()
{
	ll n;
	cin>>n;
	vector<vector<ll>>dp(n+1,vector<ll>(3,0));
	dp[1][0]=1;
	dp[2][0]=2;
	dp[2][1]=dp[2][2]=1;
	for(int i=3;i<=n;i++)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-2][0]+dp[i-1][1]+dp[i-1][2])%mo;
		dp[i][1]=dp[i][2]=(dp[i-1][1]+dp[i-2][0])%mo;
	 } 
	cout<<dp[n][0];
}	
int main()
{
	lesson1();
	return 0;
 } 
