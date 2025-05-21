#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring> 
using namespace std;
typedef long long ll;
string s;
int k;
char a,b;
ll ans;
void lesson1()
{
	cin>>k;
	cin>>s;
	cin>>a>>b;
	ans=0;
	int flag=0;
	int shu=s.size();
	for(int i=0,j=k-1;i<shu;i++,j++)
	{
		if(s[i]==a)flag++;
		if(s[j]==b)ans+=flag;
//		if (s[i]!=a)continue;
//		for(int j=i+k-1;j<shu;j++)
//		{
//			if(s[j]==b)
//				ans++;
//		}
	}
	cout<<ans;
}
int main()
{
	lesson1();
	return 0;
 } 
