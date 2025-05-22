#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	string cc,dd;
	int a,b;
	for(int i=0;i<n;i++)
	{
		
		cin>>a>>b>>cc>>dd;
		string jian=s.substr(a-1,b-a+1);
		string ss=cc+dd;
		s.erase(a-1,b-a+1);
		if(s.find(ss)!=s.npos)
		{
			string tmp=s.substr(0,s.find(ss));
			tmp+=cc;
			tmp+=jian;
			tmp+=s.substr(s.find(ss)+cc.size(),s.size()-s.find(ss)-cc.size());
			s=tmp;
		}
		else
		{
			s+=jian;
		}
	}
	cout<<s;
	return 0;
}
