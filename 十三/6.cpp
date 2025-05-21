#include<iostream>
#include<cstring>

#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
//typedef pair<ll,int> pii;
//priority_queue<pii,vector<pii>,less<pii>>q;
ll a[1000][1000];
ll sum[1000][1000]={{0}};
ll n,m,k;
ll ans=0;
ll gets(ll a,ll b ,ll c ,ll d)
{
	return sum[c][d]+sum[a-1][b-1]-sum[a-1][d]-sum[c][b-1];
}
void lesson1()
{
	//memset(sum,0,sizeof(sum));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
			
		}
	}
	for(int l=1;l<=m;l++)
	{
		for(int r=l;r<=m;r++)
		{//滑动窗口，当d增加，gets只会增大，如果gets>k，对于更大的d
		//只有将u下移，才满足gets<k，因此u，d从上到下只需要移动一次，
		//不需要重新扫描 
			ll u=1,d=1;
			while(1)
			{
				while((u<=d)&&(gets(u,l,d,r)>k))u++;
				if(u<=d)ans+=d-u+1;
				d++;
				if(d>n)break;
			}
//			for(int u=1;u<=n;u++)
//			{
//				for(int d=u;d<=n;d++)
//				{
//					if(gets(u,l,d,r)<=k)
//						ans++;
//				}
//			}
		}
	}
	cout<<ans;
}
int main()
{	
	lesson1();
	return 0;
 } 
