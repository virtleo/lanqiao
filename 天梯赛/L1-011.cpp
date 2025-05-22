#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int book[257]={0};
int main()
{
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.length();i++)
		book[s2[i]]=1;
	for(int i=0;i<s1.size();i++)
	{
		if(book[s1[i]])
			continue;
		cout<<s1[i];	
	}	
	return 0;
}
