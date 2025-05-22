#include<iostream>
#include<vector>
using namespace std;
int n,m;
//树状数组 
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
	//前缀和，差分超时 
	for(int i=1;i<n+1;i++)
	{
		int c;
		cin>>c;
//		sum[i]=sum[i-1]+a[i];
//		b[i]=a[i]-a[i-1];
		myadd(i,c,a);
	}
//	for(int i=1;i<n+1;i++)cout<<a[i]<<" ";
	int l,x,y;
	for(int i=1;i<m+1;i++)
	{
		cin>>l>>x>>y;
		if (l==1)
		{
//			a[x]+=y;
//			b[x]+=y;
//			b[x+1]-=y;
//			for(int j=x;j<n+1;j++)
//			{
//				sum[j]+=y; 
//			}
			myadd(x,y,a);
		}
		if (l==2)
		{
//			re[shu++]=sum[y]-sum[x-1];
			re[shu++]=mysum(y,a)-mysum(x-1,a);
		}
	}
	for(int i=0;i<shu;i++)
		cout<<re[i]<<'\n';
	return 0;
 } 
// 5 5
//1 5 4 2 3
//1 1 3
//2 2 5
//1 3 -1
//1 4 2
//2 1 4
 
