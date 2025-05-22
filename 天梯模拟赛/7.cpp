#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,h;
	cin>>n>>m>>h;
	int map[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
		}
	}
	int sum=0;
	int x=110,y=110;
	int jishu[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==0)
			{
							int kan=0;
				//up
				for(int k=i-1;k>=0;k--)
				{
					if(map[k][j]>=h)
					{
						break;
					}
					else if(map[k][j]<0)
					{
						kan++;
						//break;
					}
				 }
				//down
				for(int k=i+1;k<n;k++)
				{
					if(map[k][j]>=h)
					{
						break;
					}
					else if(map[k][j]<0)
					{
						kan++;
						//break;
					}				
				}
				//left
				for(int k=j-1;k>=0;k--)
				{
					if(map[i][k]>=h)
					{
						break;
					}
					else if(map[i][k]<0)
					{
						kan++;
						//break;
					}				
				}
				//right
				for(int k=j+1;k<m;k++)
				{
					if(map[i][k]>=h)
					{
						break;
					}
					else if(map[i][k]<0)
					{
						kan++;
						//break;
					}					
				}
				if(kan>=3)
				{
					sum++;
					jishu[i][j]=kan;
				}
			}
	
		}
	}
	int ma=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int jg=jishu[i][j];
			if(jg>ma)
			{
				x=i;
				y=j;
				ma=jg;
			}
		}
	}
	cout<<sum<<'\n';
	printf("%d %d",x,y);
	return 0;
 } 
