#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<climits>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mmm=3000;

ll map[mmm][mmm];//邻接矩阵 
int ans=0,n=2021,dist[mmm];//最短距离 
bool mark[mmm];//标记 
int  gcd(int a,int b)
{
	return b?gcd(b,a%b):a; 	
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
 }
void dijkstra()
{
	dist[1]=0;
	for(int i=1;i<=n;i++)
	{
		ll mi=INT_MAX;
		for(int j=1;j<=n;j++)
		{
			if(!mark[j]&&dist[j]<mi)
			{
				mi=dist[j];
				ans=j;
			}
		}
		mark[ans]=1;
		for(int j=1;j<=n;j++)
		{
			if(mark[j]&&map[ans][j]!=INT_MAX)
			{
				if(mi+map[ans][j]<dist[j])
				{
					dist[j]=mi+map[ans][j];
				}
			}
			
		}
	}
	
}
void lesson1()
{
	memset(map,INT_MAX,sizeof(map));
	for(int i=1;i<=2021;i++)
	{
		for(int j=1;j<=2021;j++)
		{
			if(abs(i-j)<=21)
			{
				int w=lcm(i,j);
				map[i][j]=w;
			}
			
				
		}
	}
	
	//dijkstra();
	cout<<dist[n];
}
struct cmp{
	bool operator()(pii a,pii b)
	{
		return a.second>b.second;
	}
};

void lesson2()
{
	priority_queue<pii,vector<pii>,cmp>q;
	int w[2029]={0};
	bool pas[2029]={0};
	vector<pii>arr[2029];
	for(int i=1;i<=2021;i++)
	{
		for(int j=1;j<=2021;j++)
		{
			if(abs(i-j)<=21)
			{
				int zhi=lcm(i,j);
				arr[i].push_back({j,zhi});
			}
		}
	}
	q.push({1,0});
	while(!q.empty())
	{
		pii t=q.top();
		q.pop();
		if(pas[t.first])
			continue;
		pas[t.first]=1;
		w[t.first]=t.second;
		for(int i=0;i<arr[t.first].size();i++)
		{
			if(!pas[arr[t.first][i].first])
			{
				q.push({arr[t.first][i].first,t.second+arr[t.first][i].second});				
			}
		}
	}
	cout<<w[2021];
}
int main()
{
	//lesson1();
	lesson2();
	return 0;
 } 
