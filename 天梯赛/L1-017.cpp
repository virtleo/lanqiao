#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

int main()
{
	string s;
	cin>>s;
	float shu=count(s.begin(),s.end(),'2');

	int bei;
	if((s[s.size()-1]-'0')&1)
	{
		bei=1;
	}
	else bei=2;
	float fu;
	float jg;
	if(s[0]=='-')
	{
		fu=1.5;
		jg=shu/(s.size()-1);
	}
	else 
	{
		fu=1;
		jg=shu/s.size();
	}
	printf("%.2f%%",jg*bei*fu*100);
	return 0;
}
