#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll; 
bool check(ll xl,ll x)
{
	if(xl%x==0&&(xl/x)%2==0)return 1;
	return 0;
}
int main()
{
	ll x=343720,y=233333,t=1;
	ll xl,yl;
	while(1)
	{
		xl=t*15;
		yl=t*17;
		if(check(xl,x)&&check(yl,y))break;
		t++;
	}
	cout<<fixed<<setprecision(2)<<sqrt(xl*xl+yl*yl);
  	// 请在此输入您的代码
  	return 0;
}
