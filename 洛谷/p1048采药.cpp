#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,m;
	cin>>t>>m;
	int time[1100],value[1100];
	for(int i=1;i<=m;i++)
	{
		cin>>time[i]>>value[i];
	}
	int f[110][1100];
	for(int i=1;i<=m;i++)
	{
		for(int j =1;j<=t;j++)
		{
			if(j<time[i])
				f[i][j]=f[i-1][j];
			else
				f[i][j]=max(f[i-1][j],f[i-1][j-time[i]]+value[i]);
		}
	}
	cout<<f[m][t];
	return 0;
}

