#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
//二分 
ll n;
ll C(ll a,ll b)//C(5,2)=C(5,3)
{
	if(b>a)
		return 0;
	if(b*2>a)b=a-b;
	ll ans=1;
	for(int i=1;i<=b;i++)
	{
		ans=ans*(a-b+i)/(i);//！！！一定要注意整除， 
		if(ans>n)return ans;
	}
	return ans;
 } 
void lesson1()
{
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return ;
	}
	//cout<<C(40,20);
	ll x=1e18,y=1e18;//r,k
	for(int i=1;i<=30;i++)//列号 
	{
		 ll l=i*2,r=n;//行号 
		 while(l<=r)
		 {
		 	ll mid=(l+r)/2;
		 	if(C(mid,i)>n)//在同一列枚举 
		 	{
		 		r=mid-1;
			 }
			else if(C(mid,i)<n)l=mid+1; 
			else{
				if(mid<x||(mid==x&&i<y)) 
				{
					x=mid;
					y=i;
				}
				break;
			} 
		 }

	}
	cout<<x*(x+1)/2+y+1;
}
int main()
{
	lesson1();
	return 0;
 } 
