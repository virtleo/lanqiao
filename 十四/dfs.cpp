#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
int t,m,n;
int a[100][100];
int mark[100]={0},aa[100],ans[100];

void lesson2_dfs(int u)//dfs深搜全排列问题 next_permutation,<algorithm> 
{
	if(u==n)
	{
		for(int i=0;i<n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
			ans[u]=i;
			lesson2_dfs(u+1);
			mark[i]=0;
			ans[u]=0;
		}
	}
}

int main()
{
	cin>>n;
	lesson2_dfs(0);
	//lesson1();
	return 0;
 } 
