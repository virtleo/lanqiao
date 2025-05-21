#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a(n,0); 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int mi=count(a.begin(),a.end(),a[0]);
	int ma=count(a.begin(),a.end(),a[n-1]);
	printf("%d %d\n%d %d",a[0],mi,a[n-1],ma);
	return 0;
 } 
