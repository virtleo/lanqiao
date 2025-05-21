#include<iostream>
#include<cstring>
#include<set>
using namespace std;
set<int> s,ss,sss;
int a[10]={5,5,10,10,15,15,20,20,25,25};
int he[1000]={0};
int count=0;
int shu=1;
int ok[10];
void bfs(int u)
{
	if (u==10)
	{
		int temp=0;
		for(int i=0;i<10;i++)
		{
			if(ok[i])
				temp+=a[i];
		}

		ss.insert(temp);
		return ;
	}
	ok[u]=1;
	bfs(u+1);
	ok[u]=0;
	bfs(u+1);
}
void lesson1()
{
	bfs(0);
	s.insert(0);
	for(int i=0;i<10;i++)
	{
		int ans=0;
		int q=0;
		for(int j=i;j<10;j++)
		{
			
			ans+=a[j];
			q+=a[10-1-j];
			s.insert(ans);
			s.insert(q);
		}
	}
	cout<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();it++)cout<<*it<<' ';
	cout<<'\n'<<s.size()<<'\n';
	for(auto x:ss)cout<<x<<' ';
	cout<<'\n'<<ss.size()<<'\n';

}
int main()
{
	lesson1(); 
	for(int i=0;i<2024;i++)
	{
		int tmp=0;
		for(int j=0;j<10;j++)
		{
			if((i>>j)&1)
				tmp+=a[j];
			sss.insert(tmp);
		}
	}
	for(auto x:sss)cout<<x<<' ';
	cout<<'\n'<<sss.size();
	return 0;
} 
