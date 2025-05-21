#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int n,m,s;
struct node{
	int v,w;
}x;
vector<node>a[10030];
bool operator<(node a,node b)
{
	return a.w>b.w;
}
priority_queue<node>que;

int main()
{
	cin>>n>>m>>s;//最好初始化在赋值之后vector 
	vector<int>wq(n+1,0);
	vector<bool>pas(m+1,0);
	for(int i=0;i<m;i++)
	{
		int u,v,w; 
		cin>>u>>v>>w;
		a[u].push_back({v,w});
	 } 
	que.push({s,0});
	while(!que.empty())
	{
		node x=que.top();
		que.pop();
		if(pas[x.v])continue;
		pas[x.v]=1;
		wq[x.v]=x.w;
		for(int i=0;i<a[x.v].size();i++)
		{
			if(!pas[a[x.v][i].v])
			{
				que.push({a[x.v][i].v,a[x.v][i].w+x.w});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<wq[i]<<' ';
	}
	return 0;
}
