#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[1000004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    dp[0]=1;
    dp[1]=2;
    for(int i=2; i<=1000000; i++){
        long long temp=0;
        temp = dp[i-1] + dp[i-2];
        dp[i] = temp%15746;
    }

    cout<<dp[n-1]%15746;
    return 0;
}