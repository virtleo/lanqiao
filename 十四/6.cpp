#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<queue> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t,m,n,ans=0;
int map[100][100],sea[100][100],road[100][100];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int ddx[]={1,0,1,0,-1,-1,1,-1};
int ddy[]={1,1,-1,-1,1,0,0,-1};
bool flag=false; 
bool check(int x,int y)
{
	return x>=0&&x<m&&y<n&&y>=0;
}
void bfs_road(int a,int b)
{
	 queue<pii>q;
	 q.push({a,b});
	 road[a][b]=1;
	 while(!q.empty())
	 {
	 	pii top=q.front();
	 	for(int i=0;i<4;i++)
	 	{
	 		int nx=top.first+dx[i];
	 		int ny=top.second+dy[i];
	 		if(map[nx][ny]&&check(nx,ny)&&!road[nx][ny])
	 		{
	 			road[nx][ny]=1;
	 			q.push({nx,ny});
			 }
		 }
	 	q.pop();
	 }
}
void dfs_road(int a,int b)
{
	if(!map[a][b]||!check(a,b)||road[a][b])
		return ;
	road[a][b]=1;
	for(int i=0;i<4;i++)
	{
		dfs_road(a+dx[i],b+dy[i]);
		//road[a+dx[i]][b+dy[i]]=0;不用回溯，只需要打上标记就ok 
	}
	//road[a][b]=0;
}
void bfs_sea(int a,int b)
{
	queue<pii>q;
	q.push({a,b});
	sea[a][b]=1;
	while(!q.empty())
	{
		pii top=q.front();
		for(int i=0;i<8;i++)
		{
			int nx=top.first+ddx[i],ny=top.second+ddy[i];
			if(!map[nx][ny]&& check(nx,ny)&&!sea[nx][ny])
			{
				q.push({nx,ny});
				sea[nx][ny]=1;
				//cout<<nx<<' '<<ny<<'\n';
			}
			if(map[nx][ny]&& check(nx,ny)&& !road[nx][ny])
			{
				ans++;
				dfs_road(nx,ny);
				//bfs_road(nx,ny);
			}
		}
		q.pop();
	}
}
void lesson1()
{
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ans=0;
		memset(sea,0,sizeof(sea));
		memset(road,0,sizeof(road));
		memset(map,0,sizeof(map));
		cin>>m>>n;
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				char ch;
				cin>>ch;
				map[j][k]=ch-'0';
			}
		}
		flag=false;
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(!j||j==m-1||k==n-1||!k)
				{
					if(!map[j][k]&&!sea[j][k])
					{
						flag=true;
						bfs_sea(j,k);
					}
				} 
			}
		} 
		if(!flag)ans=1;
		cout<<ans<<'\n'; 
//		for(int j=0;j<m;j++)
//		{
//			for(int k=0;k<n;k++)
//			{
//				
//				cout<<map[j][k]<<" ";
//			}
//			cout<<'\n';	
//		}
	}	
}
int main()
{
	lesson1();
	return 0;
 } 
