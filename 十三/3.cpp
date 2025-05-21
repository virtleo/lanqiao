#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
void lesson1()
{
	ll n,a,b;
	cin>>a>>b>>n;
	ll ti=0;
	ll tian=1;
	ll week=n/(5*a+2*b);
	ll day=n%(5*a+2*b);
	while(ti<day)
	{
		if(tian%7==6||tian%7==0)
		{
			ti+=b;
		}
		else ti+=a;
		tian++;
	}

	cout<<week*7+tian-1;
}
int main()
{
	lesson1();
	return 0;
 } 
