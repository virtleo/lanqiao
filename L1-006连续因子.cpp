#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int count ,begin;
	int max=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		int shu=n;
		count=0;
		int j=i;
		while(shu%j==0)
		{
			shu/=j;
			j++;
			count++; 
		}
		if (max<count)
		{
			max=count;
			begin=i;
		}
	}
	if (max)
	{
		cout<<max<<'\n'<<begin;
		for(int i=1;i<max;i++)
		{
			cout<<'*'<<begin+i;
		}
	}
	else 
	{
		cout<<1<<'\n'<<n;
	}
	return 0; 
} 
