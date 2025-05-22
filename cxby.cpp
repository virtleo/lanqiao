#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const ll mo=1e9+7;
ll dp[10100][10100][10100]={{{0}}};//×ÜÀ¨ºÅÊý£¬×óÀ¨ºÅ£¬ÓÒÀ¨ºÅ 
ll zuo=0,you=0;
string s;
void lesson1()
{
	dp[1][1][0]=dp[1][0][1]=1;
	dp[2][1][1]=dp[2][2][0]=dp[2][0][2]=1;

	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			zuo++;
		else you++;
	}
	for(int i=3;i<=2*zuo;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
			{
				dp[i][i-j][j]=dp[i][j][i-j]=1;
				break;
			}
			dp[i][i-j][j]+=(dp[i-1][i-j-1][j]+dp[i-1][i-j][j-1])%mo;
		}
		
	}
	cout<<dp[2*zuo][zuo][zuo]-1;
}
int main()
{
	lesson1();
	return 0;
 } 
