#include<bits/stdc++.h>
using namespace std;
//转换函数
long long Turn_to_R(double d,long long n){
	return ceil((1LL<<n)*d);
} 

int main(){
	cout<<"输入一个整数n和一个浮点数d:"<<"\n";
	double d;
	long long n;
	cin>>n>>d;
	long long R= Turn_to_R(d,n);
	cout<<"R格式："<<R<<"\n";
	return 0; 
}
