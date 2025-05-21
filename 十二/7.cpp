#include<iostream>
#include<cmath>
#include<iomanip>
#include<set>
#include<vector> 
using namespace std;
typedef long long ll;
set<ll> s;
int w,n;
void lesson1()
{
//用vecotr+set也就是枚举所有可能 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>w;
		vector<int> a(s.begin(),s.end());
		for(int i=0;i<a.size();i++)
		{
			s.insert(w+a[i]);
			if(w-a[i]!=0)
			{
				s.insert(abs(w-a[i]));
			}
		}
		s.insert(w);
	}
	cout<<s.size();
}
void lesson2()
{//dp[i][j],i表示放第i个砝码，j表示放第i个砝码后的重量
//dp[i][j]=dp[i-1][j]||dp[i-1][j+w[i]||dp[i-1][abs(j-w[i)]
//不放||放右边+||放左边-
	int dp[110][110000];
	dp[0][0]=1;//一个都没选 ，重量为0，没有意义
	int w[110];
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		sum+=w[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			dp[i][j]=dp[i-1][j] || dp[i-1][j+w[i]] || dp[i-1][abs(j-w[i])] ;
		}
	}
	int ans=0;
	for(int i=1;i<=sum;i++)
	{
		if(dp[n][i])
			ans++;
	}
	cout<<ans;
 } 
int main()
{
	//lesson1();
	lesson2(); 
	return 0;
 } 
