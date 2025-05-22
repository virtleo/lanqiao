//#include<iostream>
//#include<cstring>
//#include<algorithm>
//const long long eps=1e6+1;
//using namespace std;
//struct cf{
//    long long x,l,r;
//};
//cf f[eps];
//long long n,m,a[eps],b[eps],c[eps];
//bool check(int);
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//        cin>>a[i];
//    for(int i=1;i<=m;i++)
//        cin>>f[i].x>>f[i].l>>f[i].r;
//    if(check(m))
//        cout<<'0';
//    else
//    {
//        int l=1,r=m;
//        while(l<r)
//        {
//            int mid=(l+r)>>1;
//            if(check(mid))
//                l=mid+1;
//            else
//                r=mid;
//        }
//        cout<<"-1\n"<<l;
//    }
//    return 0;
//}
//bool check(int x)//差分 
//{
//    memset(b,0,sizeof(b));
//    for(int i=1;i<=x;i++)
//    {
//        b[f[i].l]+=f[i].x;
//        b[f[i].r+1]-=f[i].x;
//    }
//    for(int i=1;i<=n;i++)
//    {
//        c[i]=b[i]+c[i-1];
//        if(c[i]>a[i])
//            return 0;
//    }
//    return 1;
//}
#include<iostream>
#include<vector> 
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m;
const ll eps=1e6+10;
struct hire{
	ll d,s,t;
};
ll b[eps];
ll c[eps];
bool check(ll x,vector<hire>&cla,vector<ll>&r);
int main()
{
	cin>>n>>m;
	vector<ll>r(n+15,0);
	vector<hire>cla(m+15);
	for(int i=1;i<n+1;i++)
	{
		cin>>r[i];
		//b[i]=r[i]-r[i-1];
	}
	for(int i=1;i<m+1;i++)
		cin>>cla[i].d>>cla[i].s>>cla[i].t;
	if (check(m,cla,r))
	{
		cout<<'0';
	}
	else
	{
		ll l=1,r1=m;
		while(l<r1)
		{
			ll mid=(l+r1)>>1;
			if (check(mid,cla,r))
				l=mid+1;
			else r1=mid;
		}
		cout<<"-1\n"<<l;
	}

//	ll shuchu=0;
//	bool hh=true;

//		//差分 
//		b[cla[i].s]-=cla[i].d;
//		b[cla[i].t+1]+=cla[i].d;
//		for(int j=1;j<n+1;j++)
//		{
//			r[j]=r[j-1]+b[j];
//		}
//		//检查
//		for(int j=1;j<n+1;j++)
//		{
//			if(r[j]<0&&hehe)
//			{
//				shuchu=i;
//				hehe=false;
//			}
//			
//		} 
//	}
//	if (!shuchu)
//		cout<<'0';
//	else 
//		cout<<"-1\n"<<shuchu; 超时
	 
	return 0;
}

bool check(ll x,vector<hire>&cla,vector<ll>&r)
{
	memset(b,0,sizeof(b));
	for(int i=1;i<x+1;i++)
	{
		b[cla[i].s]+=cla[i].d;
		b[cla[i].t+1]-=cla[i].d;
	}
	for(int i=1;i<n+1;i++)
	{
		c[i]=c[i-1]+b[i];
		if (c[i]>r[i])
		{
			return 0;
		}
	}
	return 1;
}

