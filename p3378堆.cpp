#include<queue>
#include<vector>
#include<iostream>
/*
priority_queue<int> que;//默认为小根堆
priority_queue<int, vector<int>,less<int> > que;
priority_queue<int, vector<int>, less<int> > que;//这个也是小根堆
priority_queue<int, vector<int>, greater<int> > que;//这个是大根堆
que.push(x);//加入一个数x
cout << que.top();//输出第一个数
cout << que.size();//输出这个堆有几个元素
que.pop();//弹出第一个元素
cout << que.empty();//判断这个堆是不是空的
*/
using namespace std;
int main()
{
	int n;
	int op;
	cin>>n;
	vector<int>s(n+1,0);
	int num=0;
	priority_queue<int ,vector<int>,greater<int> > que;
	for(int i=0;i<n;i++)
	{
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			que.push(x);
		}
		else if(op==2)
		{
			//cout<<que.top();
			s[num++]=que.top();
		}
		else if(op==3)
		{
			que.pop();
		}
	}
	for(int i=0;i<num;i++)
	{
		cout<<s[i]<<endl;
	 } 
	return 0;
 } 
