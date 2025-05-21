#include<bits/stdc++.h>
using namespace std;
int cnt=0;
string s[1001];
int n,k;
int main()
{
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>k;
	cin.ignore();
	string wb;
	getline(cin,wb);
	for(int i=0;i<n;i++)
	{
		while(wb.find(s[i])!=wb.npos)
		{
			int pos=wb.find(s[i]);
			int len=s[i].size();
			wb.replace(pos,len,"~~~");
			cnt++;
		}
	}
	if(cnt<k)
	{
		for(int i=0;i<cnt;i++)
		{
			int pos=wb.find("~~~");
			wb.replace(pos,3,"<censored>");
		}
		cout<<wb;
	}
	else 
	{
		cout<<cnt<<'\n';
        cout << "He Xie Ni Quan Jia!";
	}
	return 0;
}
