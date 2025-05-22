#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 1000000007
long long func(string s){
    vector<long long> dd;
    vector<vector<long long> > dp;
    int i,j;
    for(i=0;i<=1+s.size();i++){
        dd.push_back(0);
    }
    for(i=0;i<=1+s.size();i++){
        dp.push_back(dd);
    }
    dp[0][0]=1;
    for(i=1;i<=s.size();i++){//对每个括号进行判断
        if(s[i-1]=='('){
            for(j=1;j<=s.size();j++){
                dp[i][j]=dp[i-1][j-1];
            }
        }
        else{
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%N;
            for(j=1;j<=s.size();j++){
                dp[i][j]=(dp[i-1][j+1]+dp[i][j-1])%N;
            }
        }
    }
    for(i=s.size();i>=1;i--){//等同于下面的代码，求添加左括号的方案数
        if(s[i-1]==')'&&dp[i][0]!=0)
            return dp[i][0];
    }
    /*
    for(int i=0;i<=len;i++)//len是括号序列的长度，求添加左括号的方案数
        if(dp[len][i]!=0)
        	return dp[len][i];
        return -1;
    */
    return 1;
}
int main(int argc, char** argv) {
    string s;
    cin>>s;
    long long l=0;
    l=func(s);//求添加左括号的方案数
    int i;
    for(i=0;i<s.size();i++){//将左括号变为右括号，右括号变为左括号
        if(s[i]=='(')
            s[i]=')';
        else
            s[i]='(';
    }
    reverse(s.begin(),s.end());//对括号序列翻转
    long long r=func(s);//求添加右括号的方案数
    cout<<(l*r)%N;
    return 0;
}

