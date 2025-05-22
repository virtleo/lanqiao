#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	cin.ignore();
	queue<char> q[110];
	stack<char> a;
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		for(int j=0;j<s.size();j++)
			q[i].push(s[j]);
		
	 }
	int xu;
	vector<char>line;
	while(1)
	{
		cin>>xu;
		if((xu==-1))
			break;
		else if(a.size()<s&&xu!=0)
		{
			if(q[xu].empty())continue;
			char c=q[xu].front();
			q[xu].pop();
			a.push(c);
		}
		else if(xu==0&&!a.empty())
		{
			char c=a.top();
			a.pop();
			line.push_back(c);
		}
		else if(a.size()==s&&xu!=0)
		{
			if(q[xu].empty())continue;
			char c=q[xu].front();
			q[xu].pop();
			line.push_back(a.top());
			a.pop();
			a.push(c);			
		}
//		else {
//			continue;
//		}	
	}
	for(int i=0;i<line.size();i++)
	{
		cout<<line[i];
	}
	return 0;
}
