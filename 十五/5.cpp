#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,arr[100005]={0};//arr统计宝石亮度相同的宝石数量 ,gcd(a,b,c)
void lesson1()
{ 
	cin>>n;
	int t;
	int max=0;
	for(int i=1;i<n+1;i++)
	{
		cin>>t;
		arr[t]++;//宝石亮度为t的宝石数量 
		if (t>max)max=t;
	}
	for(int i=max;i>=1;i--)
	{
		int ans=0,now=0,num[3];//ans为找到的宝石数量，now现在的宝石数量，num存宝石亮度
		for(int j=i;j<=max;j+=i)//对于每个精美度i，我们都需要寻找闪亮度为i，2i，3i...的宝石并统计数量
		{
			ans+=arr[j];
			for(int k=0;k<arr[j]&&k<3;k++)
			{
				num[now++]=j;
			}
		 }
		if(ans>=3)
		{
			cout<<num[0]<<' '<<num[1]<<' '<<num[2];
			return ;
		}
	}
}
int main()
{
	lesson1();
  	// 请在此输入您的代码
  	return 0;
}
