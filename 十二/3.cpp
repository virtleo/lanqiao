#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<pair<int,pair<int,int>>>s;
vector<pair<int,int>>a;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
//y-y1/y2-y1=x-x1/x2-x1;
void func(int x1,int y1,int x2,int y2)
{
	int a=y2-y1;
	int b=x1-x2;
	int c=x2*y1-x1*y2;
	int t=gcd(gcd(a,b),c);
	a=a/t+50;
	b=b/t+50;
	c=c/t+500;
	s.insert({a,{b,c}});
}
void lesson1()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<21;j++)
		{//一共有20*21个点 
			a.push_back({i,j});
		}
	}
	//遍历每一个点 
	for(int i=0;i<20*21;i++)
	{
		for(int j=0;j<21*20;j++)
		{
			if(i!=j)
			{
				int x1=a[i].first,y1=a[i].second;
				int x2=a[j].first,y2=a[j].second;
				func(x1,y1,x2,y2);
			}
		}
	}
	cout<<s.size();
}
int main()
{
	lesson1();
	return 0;
 } 
