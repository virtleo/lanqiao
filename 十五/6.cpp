#include<iostream>
using namespace std;
int n,k;
bool flag=0;//判断是不是找到了最终的[n-1][n-1] 
//arr为原始数组，vis为判断是否走过该点，ans存行进的方向数，crossvis判断是否有x1,y1到x2,y2的路径 
int arr[11][11],vis[11][11]={{0}},ans[121],crossvis[11][11][11][11]={{{{0}}}};
//dir为向各个方向移动的数组 
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
bool in(int x,int y)//判断是否在数组范围内 
{
	return x>=0&&x<n&&y>=0&&y<n;
}
bool cross(int x,int y,int idx)
{//x1,y1为在idx方向下向右/向下一位的坐标
//x2,y2向左 
	int x1=x+dir[(idx+1)%8][0];
	int y1=y+dir[(idx+1)%8][1];
	int x2=x+dir[(idx+7)%8][0];
	int y2=y+dir[(idx+7)%8][1];
	//判断在数组arr范围内，同时存在一个x1,y1->x2,y2的路径，即为对角线路径 
	return in(x1,y1)&&in(x2,y2)&&(crossvis[x1][y1][x2][y2]||crossvis[x2][y2][x1][y1]);
}//dfs寻找最优路径 
void dfs(int x,int y ,int kk,int depth)
{
	if(depth==n*n-1)//到arr最后一位 
	{
		if(x==n-1&&y==n-1)//x,y也为最后一位 
		{
			flag=1;//能找到从(0,0)->(n-1,n-1)的路径 
			for(int i=0;i<depth;i++)
				cout<<ans[i];//输出路径移动的方向 
		}
		return ;
	}
	for(int i=0;i<8;i++)//遍历x,y能移动的8个方向 
	{
		//xx,yy为x,y所移动后的坐标 
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(in(xx,yy)&&!vis[xx][yy]&&arr[xx][yy]==kk)//ans判断xx，yy没有走过当个节点，
		//arr表示所走的节点为顺序序列(0，1，2) 
		{
			if((i&1)&&cross(x,y,i))//如果移动为奇数，路径为对角线，
			//cross(x,y,i)判断是否已经存在i-1,i+1的对角线路径， 
			{ 
				continue;
			}
			ans[depth]=i;//第depth步的移动方向为i 
			vis[xx][yy]=1;//标记已走过 
			crossvis[x][y][xx][yy]=1;//存在路径(x,y)->(xx,yy) 
			dfs(xx,yy,(kk+1)%k,depth+1);//在当前节点继续dfs ,如果返回，表示即使走了最大步数n*n-1还是没有找到路径，只能继续遍历 
			vis[xx][yy]=0;//标记为未走过 
			crossvis[x][y][xx][yy]=0;
			if(flag)
				return ;			
		}
	}
}
void lesson1()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	vis[0][0]=1;//(0,0)已走过 
	dfs(0,0,1%k,0);
	if (!flag)
		cout<<"-1";
}
int main()
{
	lesson1();
	return 0;
}
