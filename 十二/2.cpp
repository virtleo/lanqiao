#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void lesson1()
{
	double n;
	cin>>n;
//	double jg=sqrt(2*n+0.25)-0.5;
//	cout<<round(jg)<<' ';//四舍五入 
	//cout<<fixed<<setprecision(0)<<jg;//四舍五入 
	for(int i=1;i<n;i++)
	{
		if(i*(i+1)/2>=n)
		{
			cout<<i;
			return ;
		}
	 } 
}
int main()
{
	lesson1();
	return 0;
 } 
