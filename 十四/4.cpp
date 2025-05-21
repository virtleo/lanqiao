#include<iostream>
#include<cstring>
#include<queue>
//#include<vector>由此可知，priority_queue是内置的vector 
#include<cmath> //log:e,log2:2,log10:10,logn^m:log(m)/log(n)
using namespace std;
int t,n;
int tt[11],dd[11],ll[11];
int ok[11];
bool flag=false;
void dfs(int fir,int last)//飞机，时间总和 
{
	if(fir>n)
	{
		flag=true;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!ok[i]&&tt[i]+dd[i]>=last)
		{
			ok[i]=1;
			dfs(fir+1,max(last,tt[i])+ll[i]);
			ok[i]=0;
		}
	}
}
void lesson1()
{ 
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		flag=false;
		memset(tt,0,sizeof(ok));
		memset(dd,0,sizeof(ok));
		memset(ll,0,sizeof(ok));
		memset(ok,0,sizeof(ok));
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>tt[j]>>dd[j]>>ll[j];
		}
		dfs(1,0);
		if(flag)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
		
	}
}
int main()
{
	lesson1(); 
	return 0;
} 
