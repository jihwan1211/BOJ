#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int dp[44];

int code1(int n){
    if(n == 1 || n == 2) {
        cnt++;
        return 1;
    }
    else return code1(n-1) + code1(n-2);
}

int code2(int n){
    int &ret = dp[n];
    if(ret) return ret;
    cnt++;
    dp[n] = code2(n-1) + code2(n-2);
    return dp[n];

    // for(int i=3; i<=n; i++){
    //     cnt++;
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // return dp[n];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    code1(n);
    cout<<cnt<<" ";
    cnt=0;
    dp[1]=1;
    dp[2]=1;
    code2(n);
    cout<<cnt;

    return 0;
}