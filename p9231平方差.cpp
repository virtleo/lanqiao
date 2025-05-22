#include<iostream>
using namespace std;
int odd(int x){
	return (x+1)/2;//<=xµÄÆæÊı 
}
int even(int x)
{
	return x/4;
}
int main()
{
	int l ,r;
	cin>>l>>r;
	cout<<odd(r)-odd(l-1)+even(r)-even(l-1);
	return 0;
 } 
