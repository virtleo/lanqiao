#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int t;
int zhuan(char a,char b)
{
	return ((a-'0')*10+b-'0');
}
int second(string a,int a1)
{
	int start,end;
	start=zhuan(a[0],a[1])*3600+zhuan(a[3],a[4])*60+zhuan(a[6],a[7]);
	end=zhuan(a[9],a[10])*3600+zhuan(a[12],a[13])*60+zhuan(a[15],a[16])+a1*3600*24;
	return end-start;	
}
string zero(string x)
{
	if(x.size()==1)
		return ('0'+x);
	else
		return x;
}
string shuchu(int a,int b,int c)
{
	string x,y,z;
	x=to_string(a);
	y=to_string(b);
	z=to_string(c);
	return (zero(x)+':'+zero(y)+':'+zero(z));
}
void sb(string a,string b){

	int st,en;
	int a1=0,b1=0;

	if(a.find('(')!=string::npos)
	{
		a1=a[a.find('+')+1]-'0';
	}
	if(b.find('(')!=string::npos)
	{
		b1=b[b.find('+')+1]-'0';
	}
	st=second(a,a1);
	en=second(b,b1);
	int avg=(st+en+1)/2;
	int h,m,s;
	h=avg/3600;
	m=avg%3600/60;
	s=avg%60;
	cout<<shuchu(h,m,s);

}
int main()
{

	cin>>t;
	cin.ignore();
	struct arr
	{
		string a;
		string b;
	};
	arr shu[10000];
	for(int i=0;i<t;i++)
	{
		cin>>shu[i].a>>shu[i].b; 
	}
	for(int i=0;i<t;i++)
	{
		sb(shu[i].a,shu[i].b);
		if(i!=t-1)
		cout<<endl;
	}
	return 0;
	
 } 
