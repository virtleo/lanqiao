#include<iostream>
#include<cstring>
#include<queue>
//#include<vector>由此可知，priority_queue是内置的vector 
#include<cmath> //log:e,log2:2,log10:10,logn^m:log(m)/log(n)
using namespace std;
int n;
int a[10000],b[10000];
priority_queue<int,vector<int>,greater<int>>mi;
priority_queue<int>ma;
void lesson1()
{ 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		mi.push(a[i]/b[i]);
		ma.push(a[i]/(b[i]+1));
	}
	cout<<ma.top()+1<<' '<<mi.top();
}
int main()
{
	lesson1(); 
	return 0;
} 
