#include<bits/stdc++.h>
using namespace std;
struct pii
{
	int first;
	int second;
};
bool cmp(pii a,pii b)
{
	return a.first<b.first;
}
int  tosecond(string a)
{
	int h,m,s;
	sscanf(a.c_str(),"%d:%d:%d",h,m,s);
	cout<<h<<m<<s;
	return h*3600+m*60+s;
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	vector<pii>a(n+1,{INT_MAX,INT_MAX});
	for(int i=0;i<n;i++)
	{
//		string st,en;
//		cin>>st>>en;
//		a[i].first=tosecond(st);
//		a[i].second=tosecond(en);
		int aa,bb,cc,dd,ee,ff;
		scanf("%d:%d:%d %d:%d:%d",&aa,&bb,&cc,&dd,&ee,&ff);
		a[i].first=aa*3600+bb*60+cc;
		a[i].second=dd*3600+ee*60+ff; 
	}
	sort(a.begin(),a.end(),cmp);
	int cou=1,endtime=a[0].second;
	for(int i=1;i<n;i++)
	{
		if(a[i].first>=endtime)
		{
			cou++;
			endtime=a[i].second;
		}
	}
	cout<<cou;
	return 0;
 } 
