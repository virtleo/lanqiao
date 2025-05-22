#include<iostream>
typedef long long ll;
using namespace std;
ll t[400005],a[100005],tag[400005],n,m,sum[100002];
void push_up(ll fa)
{
	t[fa]=t[fa<<1]+t[fa<<1|1];
}
void push_down(ll left, ll right,ll fa)
{
	ll mid=(left+right)>>1;
	t[fa<<1]+=tag[fa]*(mid-left+1);
	tag[fa<<1]+=tag[fa];
	t[fa<<1|1]+=tag[fa]*(right-mid);
	tag[fa<<1|1]+=tag[fa];
	tag[fa]=0;
}
void build(ll fa,ll left,ll right)
{
	if(left==right)
	{
		t[fa]=a[left];
		return ;
	}
	ll mid=(left+right)>>1;
	build(fa<<1,left,mid);
	build(fa<<1|1,mid+1,right);
	push_up(fa); 
}
ll query(ll ql,ll qr,ll left,ll right,ll fa)
{
	ll ans=0;
	if(ql<=left&&qr>=right)
		return t[fa];
	ll mid=(left+right)>>1;
	push_down(left,right,fa);
	if(ql<=mid)ans+=query(ql,qr,left,mid,fa<<1);
	if(qr>mid)ans+=query(ql,qr,mid+1,right,fa<<1|1);
	return ans;
}
void update(ll ql,ll qr,ll left,ll right,ll fa,ll k)
{
	if (ql<=left&&qr>=right)
	{
		t[fa]+=k*(right-left+1);
		tag[fa]+=k;
		return ;
	}
	push_down(left,right,fa);
	ll mid=(left+right)>>1;
	if (ql<=mid)update(ql,qr,left,mid,fa<<1,k);
	if (qr>mid)update(ql,qr,mid+1,right,fa<<1|1,k); 
	push_up(fa);
}
void lesson1()
{	
	ll shu=0;
	ll l,x,y,k;
	cin>>n>>m;
	for(int i=1;i<n+1;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);
	for(int i=1;i<m+1;i++)
	{

		cin>>l;
		if (l==1)
		{
			cin>>x>>y>>k;
			update(x,y,1,n,1,k);
		}
		else 
		{
			cin>>x>>y;
			ll jieguo=query(x,y,1,n,1);
			sum[shu++]=jieguo;
			cout<<jieguo<<'\n';
		}
	}
//	for(int i=0;i<shu;i++)
//		cout<<sum[i]<<'\n';
}
int main()
{
	lesson1();
	return 0;
}
