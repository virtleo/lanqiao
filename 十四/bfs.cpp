#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<queue>
//给定一个n x m 的二维整数数组，用来表示一个迷宫，数组中只包含0或 1，其中0 表示可以走的路，1 表可通过的墙壁。
//最初，有一个人位于左上角(1,1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。请问，该人从左上角移动至右下角(n,m)处，至少需要移动多少次。数据保证(1,1)处和(n,m)处的数字为 0，且一定至少存在一条通路。输入格式
//第一行包含两个整数 n 和 m。
//接下来 几 行，每行包含 m 个整数(0 或 1)，表示完整的二维数组迷宫。输出格式
//输出一个整数，表示从左上角移动至右下角的最少移动次数。
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
int a[1000][1000],mark[1000][1000],ans=0;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue<pii>q;//单项队列，只能在队头进行操作，q.front(),q.pop()都是在队头操作 
void lesson3_bfs()//bfs遍历图，表示都得走一遍
{
	memset(mark ,-1,sizeof(mark));
	q.push({0,0});
	mark[0][0]=0;
	while(!q.empty())
	{
		pii top=q.front();
		for(int i=0;i<4;i++)
		{
			int nx=top.first+dx[i],ny=top.second+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&mark[nx][ny]==-1&&a[nx][ny]==0)
			{
				mark[nx][ny]=mark[top.first][top.second]+1;
				q.push({nx,ny});
			}
		}
		q.pop();
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mark[i][j]<<' ';
		}
		cout<<'\n';
	}
	cout<<mark[n-1][m-1];
} 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	lesson3_bfs();
	return 0;
 } 
