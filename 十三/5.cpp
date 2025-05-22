#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100200]={0},b[100200]={0},jingzhi[100200]={0};
int main()
{
	int n;
	cin>>n;
	int ma,mb,x,y;
	cin>>ma;
	ll mo=1e9+7;
	for(int i=1;i<=ma;i++)
	{
		cin>>x;
		a[ma-i]=x;
	}	
	cin>>mb;
	for(int i=1;i<=mb;i++)
	{
		cin>>y;
		b[mb-i]=y;
	}
	ll ans=0,w=1;
	for(int i=0;i<(ma>mb?ma:mb);i++)
	{
		if(a[i]>b[i]) jingzhi[i]=a[i]+1;
		else if(a[i]==0&&b[i]==0)jingzhi[i]=2;
		else jingzhi[i]=b[i]+1;
		//jintzhi[i]=max(max(a[i],b[i])+(long long)1,(long long)2);
		ans=(ans+((a[i]-b[i])*w))%mo;
		w=(w*jingzhi[i])%mo;
	}
	cout<<ans;
	return 0;
} 
