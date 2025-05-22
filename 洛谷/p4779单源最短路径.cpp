#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int v,dis;
}x;

bool operator<(node x,node y)
{
	return x.dis>y.dis;
}
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	vector<int>w(n+5,0);
	vector<bool>pas(n+5,0);
	priority_queue<node>q;
	vector<node>arr[100005];
	int u1,v1,dis1;
	for(int i=1;i<=m;i++)
	{
		cin>>u1>>v1>>dis1;
		arr[u1].push_back({v1,dis1});
	}
	//µœΩ‹ÀπÃÿ¿≠,bfs,queue 
	q.push({s,0});
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		if(pas[x.v])continue;
		pas[x.v]=1;
		w[x.v]=x.dis;
		for(int i=0;i<arr[x.v].size();i++)
		{
			if(!pas[arr[x.v][i].v])
			{
				q.push({arr[x.v][i].v,x.dis+arr[x.v][i].dis});
			}
		}
		
	 } 
	for(int i=1;i<=n;i++)
	{
		cout<<w[i]<<' ';
	}
	return 0;
 } 
