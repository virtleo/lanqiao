#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll a,b;
int ans=0;
int sum,js;
pii aa[1000];
int shu=0;
void dfs(ll x)
{
	if(x<10)
	{
		return ;
	}
	js=1;
	while(x)
	{
		js*=x%10;
		x/=10;
	}
	sum++;
	dfs(js);
}
int main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		sum=0;

		dfs(i);
		if(sum>=ans)
		{
			ans=sum;
			aa[shu++]={i,ans};
		}
	}
	
	cout<<ans<<'\n';
	sort(aa,aa+shu);
	for(int i=0;i<shu;i++)
	{
		if(aa[i].second==ans)
		{
			cout<<aa[i].first;
			if(i!=shu-1)
				cout<<' ';	
		}
			
	}
		
	return 0;
}
