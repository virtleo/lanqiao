#include<bits/stdc++.h>
using namespace std;
int timetoseconds(string ss)
{
	int h,m,s;
	sscanf(ss.c_str(),"%d:%d:%d",&h,&m,&s);
	return h*3600+m*60+s; 
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}//ÉýÐò 
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int>>apps;
	for(int i=0;i<n;i++)
	{
		string start,end;
		cin>>start>>end;
		int st=timetoseconds(start);
		int en=timetoseconds(end);
		apps.emplace_back(st,en);
	}
	sort(apps.begin(),apps.end(),cmp);
	int count=0;
	int endtime=0;
	for(auto a:apps)
	{
		if(a.first>=endtime)
		{
			count++;
			endtime=a.second;
		}
	}
	cout<<count;
	return 0;
}
