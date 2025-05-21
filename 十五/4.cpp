#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll n,a1[1200]={0},a2[1200]={0},a3[10400]={0};
string d;
string ans="1",a="2";
string gaocheng(string s1,string s2)
{
	string jieguo;
	ll len1=s1.size();
	ll len2=s2.size();
	ll len=len1+len2;
	for(int i=0;i<s1.size();i++) 
		a1[i]=s1[len1-1-i]-'0';
	for(int i=0;i<s2.size();i++)
		a2[i]=s2[len2-i-1]-'0';
	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		{
			a3[i+j]+=a1[i]*a2[j];
			if(a3[i+j]>9)
			{
				a3[i+j+1]+=a3[i+j]/10;
				a3[i+j]%=10;
			}
		}
	}
	if(a3[len])
	{
		len++;
	}
	while(a3[len-1]==0&&len>1)
	{
		len--;
	}
	for(int i=len-1;i>=0;i--)
		jieguo+=a3[i]+'0';
	return jieguo;
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	memset(a3,0,sizeof(a3));	
}
string kuaisumi(ll b)
{
	while(b)
	{
		if(b&1)
		{
			ans=gaocheng(ans,a);
			memset(a1,0,sizeof(a1));
			memset(a2,0,sizeof(a2));
			memset(a3,0,sizeof(a3)); 
		}
		b>>=1;
		a=gaocheng(a,a);
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
	}
//	cout<<ans;
	return ans;
}
int main()
{
	cin>>n;
	cin>>d;
	ll dian;
	string s1,s2;
	s1=(kuaisumi(n));
	s2=d;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]=='.')
		{
			dian=i;
			break;	
		}
	}
	for(int i=dian;i<s2.size();i++)
	{
		s2[i]=s2[i+1];
	}
	int xiaoshu=s2.size()-1-dian;
	s2.pop_back();
	string jieguo=gaocheng(s1,s2);
//	cout<<jieguo<<'\n';
	int jieguoshu=jieguo.size();
	for(int i=jieguoshu-1;i>(jieguoshu-xiaoshu-1);i--)
	{
		if (i==(jieguoshu-xiaoshu))
		{
			if(jieguo[i]>='5')
				jieguo[i-1]+=1;
//			cout<<jieguo<<'\n';
		}
		jieguo.pop_back();
	}
	cout<<jieguo;
	
	
}
