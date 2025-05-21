#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	cin.ignore();
	string jieguo="Wo AK le";
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		if(s.find("qiandao")!=string::npos)
		{
			continue;
		}
		if(s.find("easy")!=string::npos)
		{
			continue;
		}
		if(!m)
			jieguo=s;
		m--;
	}
	cout<<jieguo;
	return 0;
 } 
