#include<iostream>
#include<vector>
using namespace std;
int n,m;
//Ê÷×´Êý×é 2
void myadd(int pos,long long  b,vector<long long>&arr)
{
	while(pos<=n)
	{
		arr[pos]+=b;
		pos+=pos&-pos;
	}
}
int mysum(int pos,vector<long long>&arr)
{
	int ans=0;
	while(pos)
	{
		ans+=arr[pos];
		pos-=pos&-pos;
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	int shu=0;
	vector<long long>a(n+5,0);
	vector<long long>sum(n+5,0);
	vector<long long>b(n+5,0);
	vector<long long>re(m+5,0);
	int d=0;
	for(int i=1;i<n+1;i++)
	{
		int c;
		cin>>c;
		myadd(i,c-d,a);
		d=c;
	}
	int l;
	for(int i=1;i<m+1;i++)
	{
		cin>>l;
		if (l==1)
		{
			int x,y,k;
			cin>>x>>y>>k;
			myadd(x,k,a);
			myadd(y+1,-k,a);
		}
		if (l==2)
		{
			int x;
			cin>>x;
			re[shu++]=mysum(x,a);
		}
	}
	for(int i=0;i<shu;i++)
		cout<<re[i]<<'\n';
	return 0;
 } 
