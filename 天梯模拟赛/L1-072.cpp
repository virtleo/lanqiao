#include<bits/stdc++.h>
using namespace std;
int main()
{
	int chusheng;
	int shu[10]={0};
	vector<vector<int>>a(4,vector<int>(4,0));
	vector<vector<int>>b(4,vector<int>(4,0));
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			cin>>a[i][j];
			shu[a[i][j]]++;
			if(a[i][j]==0)
			{
				for(int k=1;k<10;k++)
					if(shu[k]==0)
					{
						b[i][j]=k;
						a[i][j]=k;
						chusheng=k;
					}
					
				
			}
		}
	}
	int jb[]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
	for(int i=0;i<3;i++)
	{
		int x,y;
		cin>>x>>y;
		if(a[x][y])
			b[x][y]=a[x][y];
		cout<<b[x][y]<<'\n';
	}
	int hua;
	cin>>hua;
	int sum=0;
	for(int i=1;i<4;i++)
	{
		if (hua<4)
		{
			if(a[hua][i])
				b[hua][i]=a[hua][i];
			sum+=b[hua][i];
		}
		else if (hua<7)	
		{
			if(a[i][hua-3])
				b[i][hua-3]=a[i][hua-3];
			sum+=b[i][hua-3];			
		}
		else if(hua==7)
		{
			if(a[i][i])
				b[i][i]=a[i][i];
			sum+=b[i][i];
		}
		else if((hua==8))
		{
			if(a[i][4-i])
				b[i][4-i]=a[i][4-i];
			sum+=b[i][4-i];
		}
	}
//	for(int i=1;i<4;i++)
//	{
//		for(int j=1;j<4;j++)
//		{
//			if(b[i][j]!=0&&b[i][j]!=chusheng)
//				cout<<b[i][j]<<'\n';
//		}
//	}
	cout<<jb[sum];
	return 0;
 } 
