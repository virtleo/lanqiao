#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll a[100100];
void lesson1()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=0;i<m;i++)
	{
		ll p,q;
		cin>>p>>q;
		if(p==0)
		{
			sort(a+1,a+q+1,greater<ll>());
			//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
			//cout<<'\n';
		}
		else
		{
			sort(a+q,a+n+1);

			//cout<<'\n';
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}
void lesson2()
{
	cin>>n>>m;
	int left=1,right=n,top=0,k=n;
	pair<int,int>stk[100200];
	while(m--)
	{
		int p,q;
		cin>>p>>q;
		if(p==0)//前缀降序
		{
			while(top&&stk[top].first==0)
			{
				q=max(q,stk[top--].second);
			}
			while(top>=2&&stk[top-1].second<=q)
			{
				//如果当前操作比上一次相同操作的范围要大，前两次操作无效化 
				top-=2;
			}
			stk[++top]={0,q};
		 } 
		else if(top)//后缀升序 
		{
			while(top&&stk[top].first==1)
			{
				q=min(q,stk[top--].second);
			}
			while(top>=2&&stk[top-1].second>=q)
			{
				top-=2;
			 } 
			stk[++top]={1,q};
		}
	}
	for(int i=1;i<top+1;i++)
	{
		if(stk[i].first==0)//固定的是最右边的 
		{
			while(right>stk[i].second&&left<right+1)
			{
				a[right--]=k--;
			}
		}
		else
		{
			while(left<stk[i].second&&left<right+1)
			{
				a[left++]=k--;
			}
		}
		if(left>right)
		{
			break;
		}
	}
	if(top%2)//后缀升序
	//栈 [p=0, p=1]（长度为 2，偶数）：最后一个操作是 p=1，剩余部分应升序。 
	{
		while(left<right+1)
		{
			a[left++]=k--;
		}
	}
	else {//前缀降序 
	//栈 [p=0, p=1, p=0]（长度为 3，奇数）：最后一个操作是 p=0，剩余部分应降序。
		while(left<right+1)
		{
			a[right--]=k--;
		}
	}
	for(int i=1;i<n+1;i++)
	{
		cout<<a[i]<<' ';
	}
 } 
int main()
{
	//lesson1();
	lesson2();
	return 0;
 } 
