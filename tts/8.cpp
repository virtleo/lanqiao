#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
struct nod{
	int m,mx,my;
}x;
bool cmp(nod a,nod b)
{
	return a.m>b.m;
}
vector<nod>ma;
int map[1100][1100];
int n,m,k,shu=0;
void lesson1()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]!=0)
				ma.push_back({map[i][j],i,j});
		}
	}
	sort(ma.begin(),ma.end(),cmp);
}
int main()
{

	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
		}
	}
//	int a=0;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<ma[a++].mx<<' ';
//		}
//		cout<<'\n';
//	}
	int ji=0;
	for(int kk=0;kk<k;kk++)
	{
		lesson1();
		for(int i=0;i<n;i++)
		{
			map[i][ma[ji].my]=0;
		}
		for(int i=0;i<m;i++)
		{
			map[ma[ji].mx][i]=0;
		}
		ma.clear();
	}
	string s;
	for(int i=0;i<n;i++)
	{
		bool f=false;
		for(int j=0;j<m;j++)
		{

			if(map[i][j]!=0)
			{
				s+=to_string(map[i][j])+' ';
				f=true;
			}
		}
		if(f&&!s.empty())
		{
			s.pop_back();
			s+="\n";	
		}
	}

	cout<<s;
	return 0;
 } 
