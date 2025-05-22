#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s1,s2;
	cin>>s1>>s2;//ÉÙÓÃgetline 
	int len=s1.size();
	int lst=-1,ans=0,state=-1;
	for(int i=0;i<s2.size();i++)
	{
		if(s1[i]=='.'&&s2[i]=='.')
		{
			continue;
		}
		if(lst!=-1)
		{
			ans+=i-lst-1;
		} 
		if(s1[i]=='#'&&s2[i]=='#')
		{
			state=3;
		}
		else if(s1[i]=='#'&&s2[i]=='.')
		{
			if(state==2)
			{
				ans++;
				state=3;
			}
			else
			{
				state=1;
			}
		}
		else if(s1[i]=='.'&&s2[i]=='#')
		{
			if(state==1)
			{
				ans++;
				state=3;
			}
			else {
				state=2;
			}
		}
		lst=i;
		
	}
	cout<<ans;
	return 0;
 } 
