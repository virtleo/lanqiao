#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
bool cmp(int a,int b)
{
	return a>b;
}
using namespace std;
int main() 
{
	int n,m;
	vector<int> arr;

	cin>>n>>m;
	vector<int>sum(n-m+1,0);
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	for(int i=0;i<=(n-m);i++)
	
	{
		for(int j=0;j<m;j++)
		{
			sum[i]+=arr[i+j];
		}
		
	}

	sort(sum.begin(),sum.end(),cmp);
	for(int num:sum)
	{
			cout<<num<<" ";
	}

	return 0;
}
