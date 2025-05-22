#include<bits/stdc++.h>
using namespace std;
string zhi(string s)
{
	string ss;
	for(int i=1;i<s.size();i++)
	{
		if((s[i]-'0')%2==(s[i-1]-'0')%2)
			ss+=max(s[i],s[i-1]);
	}
	return ss;
}
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	string ss1=zhi(s1);
	string ss2=zhi(s2);
	if(ss1==ss2)
	{
		cout<<ss1;
	}
	else{
		cout<<ss1<<'\n'<<ss2;
	}
	return 0;
 } 
