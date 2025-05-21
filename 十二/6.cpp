#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
typedef long long ll;
const ll yueshu=86400000;
//string bulin(ll s)
//{
//	if(s<10)
//	{
//		return "0"+to_string(s);
//	}
//	return to_string(s);
//}
void lesson1()
{
	ll n;
	cin>>n;
	n%=yueshu;
	n/=1000;
	int hour,minate,second;
	hour=n/3600;
	minate=n%3600/60;
	second=n%60;
	if(hour<10)cout<<"0";
	cout<<hour<<':';
	if(minate<10)cout<<'0';
	cout<<minate<<':';
	if(second<10)cout<<'0';
	cout<<second;
	//cout<<bulin(hour)<<":"<<bulin(minate)<<':'<<bulin(second);
	
}
int main()
{
	lesson1();
	return 0;
 } 
