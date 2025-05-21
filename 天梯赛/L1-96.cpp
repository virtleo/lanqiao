#include<bits/stdc++.h>
using namespace std;
int he(int a)
{
	int s=0;
	while(a)
	{
		s+=a%10;
		a/=10;
	}
	return s;
}

int main()
{
	int a,b,n;
	cin>>n;
	int sum1,sum2;
	for(int i=0;i<n;i++)
	{
		sum1=0;
		sum2=0;
		cin>>a>>b;
		sum1=he(a);
		sum2=he(b);
		if(a%sum2==0&&b%sum1!=0)
		{
			cout<<"A\n";
		}
		else if(b%sum1==0&&a%sum2!=0)
		{
			cout<<"B\n";
		}
		else 
		{
			a>b?cout<<"A\n":cout<<"B\n";
		}
	}
	return 0;
}
