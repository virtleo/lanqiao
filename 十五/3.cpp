#include <iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int n,count=0;
bool haoshu(string s)
{
	int len=s.size();
  for(int i=len-1;i>=0;i--)
  {
    if ((len-i)%2==0)
    {
      if((s[i]-'0')&1)
        return 0;
    }
    else {
      if((s[i]-'0')%2==0)
        return 0;
    }  
  }
  return 1;
}
void lesson1()
{ 
  cin>>n;
  for(int i=1;i<n+1;i++)
  {
    if(haoshu(to_string(i)))
    {
    	count++;
//    	cout<<i<<' ';
    	
	}

      
  }
  cout<<count;
}
int main()
{
  lesson1();
  // 请在此输入您的代码
  return 0;
}
