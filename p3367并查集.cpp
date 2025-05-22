#include<iostream>
#include<vector>
using namespace std;
long long  n,m;
vector<int>f(2e5+1,0);
vector<char>cc(2e6+1,0);
int shu=0;
int find(int a)
{
	if(f[a]==a)return a;
	
	return f[a]=find(f[a]);
}
int p1,p2,p3;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		f[i]=i;
	}

	for(int i=0;i<m;i++)
	{
		cin>>p1>>p2>>p3;
		if(p1==1)
		{
			f[find(p2)]=find(p3);
		 } 
		else
		{
			if(find(p2)==find(p3))
			{
				cc[shu++]='Y';
				cout<<"Y"<<endl;
				//printf("Y\n");
			}
			else
			{
				cc[shu++]='N';
				cout<<"N"<<endl;
				//printf("N\n")£» 
			}
		}
	}
//	for(int i=0;i<shu;i++)
//	{
//		cout<<cc[i]<<endl;
//	}
	return 0;
}
