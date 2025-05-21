#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int n,m; 
map<pii,int>id;
vector<int>ma[101000];//存树 
int w[101000]={0};//编号为id的路径的权值 /每个点的边权或点权 
int ans=-1;
bool dfs(int s,int u,int fa,int v)
{//s为开始节点，u为现在的节点，fa为父节点，v为结束的节点 
	if(u==v)
	{
		return true;
	}
	for(int i=0;i<ma[u].size();i++)
	{
		int son=ma[u][i];
		if(son==fa)
			continue;
		if(dfs(s,son,u,v))//如果存在s->v的路径，在路径上的权值都加一 
		{
			w[id[{u,son}]]++;	
			return true;
		}
	}
	return false;
}
void lesson1()//dfs暴力 
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y; 
		ma[x].push_back(y);
		ma[y].push_back(x); 
		id[{x,y}]=i;
		id[{y,x}]=i;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		dfs(a,a,-1,b);//从a->b的路径 
	}
	for(int i=n-1;i>0;i--)
	{
		//cout<<w[i]<<'\n';
		if(w[i]==m)//表示存在已经走过m遍的公共边 
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
 }
void lesson2()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y; 
		ma[x].push_back(y);
		ma[y].push_back(x); 
		id[{x,y}]=i;
		id[{y,x}]=i;
	}
		
}
int main()
{
	lesson1();
	//lesson2();
	return 0;
}
