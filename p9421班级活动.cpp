	#include<iostream>
	#include<vector>
	using namespace std;
	int main()
	{
		int n;
		long long s[100001]={0};
		cin>>n;
		int a;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			s[a]++;
		}
		int ans=0,d=0,ss=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==2)
				continue;
			else if(s[i]>2)
			{
				d+=(s[i]-2); 
			}
			else if(s[i]==1)
				ss+=2-s[i]; 
		}
		if(d>=ss)
		{
			ans+=ss;
			d-=ss;
			ss=0;	
		 } 
		else
		{
			ans+=d;
			ss-=d;
			d=0;
		}
		cout<<d+ss/2+ans;//注：d为>2（相同编号）的数，两个数都得变，而ss是=1的数，两个只需要变一个就可以 
		return 0;
	 } 
