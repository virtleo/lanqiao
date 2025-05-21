#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int col[1000];
	for(int i=1;i<=n;i++)cin>>col[i];
	int k;
	cin>>k;
	int a;
	bool flag=false;
	for(int i=1;i<=k;i++)
	{
		flag=false;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			if(a==0)
				cnt++;
			if(a!=0&&a!=col[j])
			{
				flag=true;
			}	
		}
		
		if(flag||cnt==n)cout<<"Ai Ya\n";
		else cout<<"Da Jiang!!!\n";
	}

	return 0;
}
