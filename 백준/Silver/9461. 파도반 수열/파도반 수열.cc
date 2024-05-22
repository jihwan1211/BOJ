#include <bits/stdc++.h>
using namespace std;

int t, k;
long long dp[104];

void go(){
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    for(int i=4; i<=100; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    go();

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>k;
        cout<<dp[k]<<"\n";
    }
    return 0;
}