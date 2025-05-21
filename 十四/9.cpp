#include<bits/stdc++.h>
//#define int long long;
using namespace std;
typedef pair<int,int>pii;
int n,k;//n个节点，无联通的无向图，即为树 
priority_queue<pii,vector<pii>,greater<pii>>q;//不用digstra 
vector<pii>a[102000];//存储图的邻接点 
int line[102000];//路线，
map<pii,int>st;// 从x到y的值 （line1->line2） 
bool dfs(int s,int u,int fa,int v,int sum)
{//s为开始的节点，u为当前的节点，fa为父节点，v为结束节点，sum为从s->v的路上权值 
	if(u==v)
	{//无向图，从s->v的值 
		st[{s,v}]=sum;
		st[{v,s}]=sum;
		return true;
	}
	for(int i=0;i<a[u].size();i++)
	{//bfs遍历u的邻接点 
		int son=a[u][i].first;
		if(son==fa)//如果是从fa->u/u->fa的，不予考虑 
			continue;
		int w=a[u][i].second;//u->son权值为w 
		if(dfs(s,son,u,v,sum+w))//如果存在s->v的的路径，返回true 
			return true;
	}
	return false;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v,t;
		cin>>u>>v>>t;
		//无向图（不连通成环），可以用邻接矩阵也可以用vecotr 
		a[u].push_back({v,t});
		a[v].push_back({u,t});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>line[i];//路线 
	}
	int ans=0;
	//求出完整路线的总花费 
	for(int i=1;i<k;i++)
	{
		dfs(line[i],line[i],-1,line[i+1],0);
		ans+=st[{line[i],line[i+1]}];
		//cout<<st[{line[i],line[i+1]}]<<'\n';
	}
	//cout<<ans<<'\n';
	int tmp;
	for(int i=1;i<=k;i++)
	{
		tmp=ans;
		if(i==1)
		{
			//cout<<tmp<<'\n';
			//cout<<st[{line[i],line[i+1]}];
			tmp-=st[{line[i],line[i+1]}];
		}
		else if(i==k)
		{
			tmp-=st[{line[i-1],line[i]}];
		}
		else 
		{
			tmp-=st[{line[i],line[i+1]}];
			tmp-=st[{line[i-1],line[i]}];
			dfs(line[i-1],line[i-1],-1,line[i+1],0);
			tmp+=st[{line[i-1],line[i+1]}];
		}
		cout<<tmp<<' ';
	 }
//	for(auto x:st)
//	{
//		
//		cout<<x.dis.first<<" "<<x.v<<'\n';
//	 } 
	return 0;
 } 
