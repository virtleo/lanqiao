#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nv,nan,n;
	cin>>nv>>nan>>n;
	bool flag=false;
	int nan_nn,nv_nn,cha=1e9; 
	for(int i=1;i<n&&i<nv&&(n-i)<nan;i++)
	{
		if(nv%i==0&&nan%(n-i)==0)
		{
			flag=true;
			int nan_n=nan/(n-i);
			int nv_n=nv/i;
			if(cha>abs(nan_n-nv_n))
			{
				cha=abs(nan_n-nv_n);
				nan_nn=(n-i);
				nv_nn=i;
			}
		}
	}
	if(flag)printf("%d %d",nv_nn,nan_nn);
	else cout<<"No Solution";
	return 0;
}
