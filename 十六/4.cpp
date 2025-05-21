#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t,a,b,c,k;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b>>c>>k;
		int aa=a,bb=b,cc=c;
		for(int j=0;j<k;j++)
		{
			a=(bb+cc)/2;
			b=(aa+cc)/2;
			c=(aa+bb)/2;
			aa=a;bb=b;cc=c;
			if(a==b&&b==c)
			{
				break;
			}

			
		}
		cout<<aa<<' '<<bb<<' '<<cc<<'\n';
	}
	return 0;
 } 
