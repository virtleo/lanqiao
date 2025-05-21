#include<iostream>
#include<cstring>
#include<queue>
//#include<vector>由此可知，priority_queue是内置的vector 
#include<cmath> //log:e,log2:2,log10:10,logn^m:log(m)/log(n)
using namespace std;
int k,ans=0;
long long a[100010];
int f[100010][10],f1[100010];
int find_fir(int a)
{
	int tou;
	while(a)
	{
		tou=a%10;
		a/=10;
	}
	return tou;
}
int find_last(int a)
{
	return a%10;
}
void lesson1()
{//dp //多决策问题，需要用到dp  
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=k;i++)
	{
		//delete
		for(int j=0;j<10;j++)f[i][j]=f[i-1][j];
		//reserve
		int last=find_last(a[i]);
		int first=find_fir(a[i]);
		f[i][last]=max(f[i-1][first]+1,f[i-1][last]);
	 } 
	for(int i=0;i<10;i++)
	{
		//cout<<f[k][i]<<' ';
		ans=max(ans,f[k][i]);
	}
	cout<<k-ans;
}
void dfs(int now,int cnt,int last)
{
	if(now==k)
	{
		ans=max(ans,cnt); 
		return ;
	}
	if(k-now+cnt<ans)return ; 
	if(last==0||find_last(last)==find_fir(a[now]))
	{
		dfs(now+1,cnt+1,a[now]);
	}
	dfs(now+1,cnt,last);
}
void lesson2()
{//dfs :枚举所有的方案，判断是否合法，选出最优解 //超时 
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
	 }
	dfs(0,0,0); 
	cout<<k-ans;
}
void lesson3()
{//dp //多决策问题，需要用到dp  
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=k;i++)
	{
		//delete
		//for(int j=0;j<10;j++)f[i][j]=f[i-1][j];
		//reserve
		int last=find_last(a[i]);
		int first=find_fir(a[i]);
		f1[last]=max(f1[first]+1,f1[last]);
		ans=max(ans,f1[last]);
	 } 
	cout<<k-ans;
}
int main()
{
	lesson1(); 
	//lesson2();
	return 0;
} 
