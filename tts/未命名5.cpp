#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	int book[257]={0};
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		book[s[i]]++;
	}
	vector<int>a;
	for(int i=0;i<26;i++)
	{
		int shu;
		cin>>shu;
		a.push_back(shu);
	}
	int jieguo=0,ji=0;
	for(int i='a';i<='z';i++)
	{
		if(i!='z')
			cout<<book[i]<<' ';
		else 
			cout<<book[i];
		jieguo+=a[ji++]*book[i];
		
	}
	cout<<'\n'<<jieguo;
	return 0;
 } 
