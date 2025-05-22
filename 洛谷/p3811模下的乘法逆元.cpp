#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n,p;
	cin>>n>>p;
	vector<long long>inv(n+1,0); 
	inv[1]=1;
	cout<<1<<endl;
	for(int i=2;i<n+1;i++)
	{
		inv[i]=((p-p/i)*inv[p%i])%p;
		cout<<inv[i]<<"\n";
	}
	return 0;
}
