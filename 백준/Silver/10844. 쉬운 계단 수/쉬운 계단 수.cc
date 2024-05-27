#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[104][12];
long long ret;

// 1에서 0이 나오고
// 8에서 9가 나온다


void go(){
    for(int i=1; i<=9; i++) dp[1][i] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=9; j++){
            if(j==0) dp[i+1][j+1] += dp[i][j]%1000000000;
            else if(j==9) dp[i+1][j-1] += dp[i][j]%1000000000;
            else{
                dp[i+1][j-1] += dp[i][j]%1000000000;
                dp[i+1][j+1] += dp[i][j]%1000000000;
            }   
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    go();
    for(int i=0; i<=9; i++){
        ret += dp[n][i]%1000000000;
    }
    cout<<ret%1000000000;
    return 0;
}