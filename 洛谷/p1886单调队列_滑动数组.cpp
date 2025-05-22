#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	deque<int>q(n+1,0);
	vector<int>a(n+1,0);
	for(int i=1;i<n+1;i++)
	{
		cin>>a[i];
	}
	//最小 
	for(int i=1;i<n+1;i++)
	{
		//队头 
		while(!q.empty()&&a[q.front()]>=a[i])
		{
			q.pop_front();
		}
		//队尾
		while(!q.empty()&&i-q.back()>=k)
		{
			q.pop_back();
		}
		//入队
		q.push_front(i);
		if(i>=k)
		{
			cout<<a[q.back()]<<' ';
		}

	}
	cout<<endl;
	q.clear();
	//最大 
	for(int i=1;i<n+1;i++)
	{
		//队头 
		while(!q.empty()&&a[q.front()]<=a[i])
			q.pop_front();
		//队尾
		while(!q.empty()&&i-q.back()>=k)
			q.pop_back();
		//入队
		q.push_front(i);
		if(i>=k)
		{
			cout<<a[q.back()]<<' ';
		}
	}
	return 0;
}
