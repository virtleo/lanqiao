#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,s,t;
	cin>>T>>s>>t;
	if(T>35&&s==1&&t>=33)
	{
		cout<<"Bu Tie"<<'\n'<<T;
	}
	else if(T>35&&s==0&&t>=33)
	{
		printf("Shi Nei\n%d",T);
	}
	else if(s==1)
	{
		printf("Bu Re\n%d",t);
	}
	else {
		printf("Shu Shi\n%d",t);
	}
	return 0;
 } 
