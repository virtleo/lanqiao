#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	stack<int> dec;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<int>arr(n+1,0);
	for(int i=n;i>0;i--)
	{
		while(!dec.empty()&&a[i]>=a[dec.top()])
		{
			dec.pop();
		}
		arr[i]=dec.empty()?0:dec.top();
		dec.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}


/*原做法，时间复杂度为o(n^2) tle
	vector<long long>arr(n+1,0);
	int sum=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				arr[sum++]=j;
				break;
			}
			if(j==n&&a[i]>a[j])
			{
				arr[sum++]=0;
			}
			
		}
	}
	arr[sum++]=0;
	for(int i=0;i<sum;i++)
	{
		cout<<arr[i]<<" ";
	}
*/
	return 0;
}
