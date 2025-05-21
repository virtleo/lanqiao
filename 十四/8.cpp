#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<utility>//用pair<t1,t2>p,make_pair(a,b),a.first,a.second 
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int mmm=5e6;
ll n,k;
ll a[mmm],l[mmm],r[mmm],cnt[mmm]={0};//cnt判断更新后的a[i]的数字 
//struct pait{
//	ll shu;
//	int biao;
//};	
//struct cmp{
//    bool operator()(const pait& s, const pait& t) {
//    	if(s.shu==t.shu)return s.biao>t.biao;
//        return s.shu > t.shu; // 大顶堆逻辑
//    }
//};
//priority_queue<pait,vector<pait>,cmp>q;
priority_queue<pii,vector<pii>,greater<pii>>q;
void lesson1()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[i]=a[i]; 
		q.push({a[i],i});
		l[i]=i-1;
		r[i]=i+1;
	}
	while(k)
	{
//		int num=q.top().shu;
//		int id=q.top().biao;
		ll num=q.top().first;
		int id=q.top().second;
		q.pop();
		if(num!=cnt[id])
		{
			q.push({cnt[id],id});
			continue;
		}
		k--;
		if(l[id]>0)
		{
			cnt[l[id]]+=num;
			r[l[id]]=r[id];
		}
		if(r[id]<=n)
		{
			cnt[r[id]]+=num;
			l[r[id]]=l[id];
		}
		cnt[id]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>-1)
			cout<<cnt[i]<<' ';
	}

}
int main()
{
	lesson1(); 
	return 0;
} 
