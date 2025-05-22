#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void lesson1()
{
	string jiu="2022";
	int jg=0;
	for(int i=jiu.size()-1;i>=0;i--)
	{
		int a=((jiu[i]-'0')*pow(9,(jiu.size()-i-1)));
		jg+=a;
	}
	cout<<jg;
}
int main()
{
	lesson1();
	return 0;
 } 
