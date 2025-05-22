#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[10009]={0},b[10009]={0},n;
bool zuo=true,you=false;
bool nixu(ll aa[])
{
	for(int i=0;i<n;i++)
	{
		if(aa[i]!=i)
			return false;
	}
	return true;
}
void lesson1()
{
	ll xu=0;
	cin>>n;
	if(n==2)
	{
		b[n-1]=2;
		b[n-2]=2;
		return ;
	}
	while(!nixu(a))
	{

		if(zuo)
		{
			if(xu<0)xu+=2;
			for(int i=0;i<n;i++)a[i]++;
			if(a[xu]>b[xu])b[xu]=a[xu];
			a[xu]=0;
			if (xu==n-1)
			{
				zuo=false;
				you=true;
			}
			xu++;
		}
		if(you)
		{
			if(xu>=n)xu-=2;
			for(int i=0;i<n;i++)a[i]++;
			if(a[xu]>b[xu])b[xu]=a[xu];
			a[xu]=0;
			if (xu==0)
			{
				zuo=true;
				you=false;
			}
			xu--;
			
		}
	}
}
int main()
{	
	lesson1(); 
	for(int i=0;i<n/2;i++)
	{
		b[n-1-i]=b[i];
	}
	for(int i=0;i<n;i++)
	cout<<b[i]<<'\n';

	return 0;
 } 
