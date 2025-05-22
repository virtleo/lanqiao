#include<iostream>
#include<cstring>
#include<cmath> //log:e,log2:2,log10:10,logn^m:log(m)/log(n)
using namespace std;
const double eps=1e-6;
long long chuxian=1233;
void lesson1()
{//需要注意的是浮点数进行运算，最好都换成浮点数，或者将整型转为浮点数，否则会出现小数变整数的情况。 
	double count=23333333;
	double jg=0;
	for(int i=1;i<=count/2;i++)
	{	
		jg=0;
		double count1=i;
		double count2=count-count1;
		double c1=double(count1)/count;
		double c2=double(count2)/count;
		jg-=(c1*count1*log2(c1));
		jg-=(c2*count2*log2(c2));	
		if(jg>11625907.5&&jg<11625907.6)
		{
			chuxian=count1;
			cout<<chuxian<<'\n';
			return ;
		}
	}
}
int main()
{
	lesson1(); 
	return 0;
} 
