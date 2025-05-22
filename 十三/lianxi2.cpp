#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(char a ,char b)
{
	return a<b;//sheng,if jiang,prev_permutation
}
void lesson1()
{
	string s="abcjwfewnvb";
	sort(s.begin(),s.end(),cmp);
	cout<<s<<'\n';
	while(next_permutation(s.begin(),s.end()))
	{
		cout<<s<<' ';
	}
}
bool jishu(int a)
{
	for(int i=0;i<to_string(a).size();i++)
		if(!((a>>(i*9)&1)))return false;
	return true;
}
void lesson2()
{
	int shu=2019;
	while(!jishu(shu))
		shu+=2019;
	cout<<shu;
}
void lesson3()
{
	long long sum=0;
	long long jc=1;
	for(int i=1;;i++)
	{
		jc*=i;
		jc%=1000000000;
		sum+=jc;
		sum%=1000000000;
		if(jc==0)
		break;
		 
	}
	cout<<sum;
}
int main()
{
	lesson3();
	return 0;
}
