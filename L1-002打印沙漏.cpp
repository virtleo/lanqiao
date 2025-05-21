#include<iostream>
#include<stack>
using namespace std;
void shuchu(char ch,int a)
{

	for (int i=0;i<a;i++)
		cout<<ch;
}
int main()
{
    int n;
    char ch;
    cin>>n>>ch;
    stack<int> pus;
    int ban=(n-1)/2;
    int num=0;
    int ma=0;
    for(int i=1;i<ban+1;i+=2)
    {
        if (num+i<=ban)
        {
            pus.push(i);
            num+=i;
            ma=i;
        }
    }
    while (!pus.empty())
    {
        shuchu(' ',(ma-pus.top())/2);
        shuchu(ch,pus.top());
		cout<<endl;
        pus.pop();
    }
    for(int i=3;i<ma+1;i+=2)
    {
        shuchu(' ',(ma-i)/2);
        shuchu(ch,i);
        cout<<endl;
        num+=i;
    }
    if(n==1)
    {
        cout<<ch<<endl;
        cout<<0;
        return 0;
    }
    cout<<n-num<<endl;
    return 0;
}
