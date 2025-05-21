#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
pii stu[100100];
int main()
{
	int n,k,s;
	int he=0,shu=0;
	cin>>n>>k>>s;
	int pici[300]={0};
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].first>>stu[i].second;
		if(stu[i].first>=175&&stu[i].second>=s)
			he++;
		else if(stu[i].first>=175&&stu[i].second<s)
		{
			pici[stu[i].first]++;
		}
	}
	for(int i=175;i<=290;i++)
	{
		if(pici[i]<=k)
			he+=pici[i];
		else 
			he+=k;
	}
	cout<<he;
	return 0;
}
