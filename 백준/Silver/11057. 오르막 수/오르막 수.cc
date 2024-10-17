#include <bits/stdc++.h>
using namespace std;

long long dp[1002][10];
int n;

long long calc(int num, int from){
    long long ret = 0;
    for(int i=0+from; i<10; i++){
        ret += dp[num-1][i]%10007;
    }

    return ret%10007;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<10; i++) dp[1][i] = 1;

    for(int i=2; i<=1000; i++){
        for(int j=0; j<10; j++){
            if(j==0) dp[i][j] = calc(i, 0);
            // else dp[i][j] = (dp[i][j-1] - dp[i-1][j-1]);
            else dp[i][j] = calc(i, j);
        }
    }
    cout<<calc(n+1, 0) % 10007;

    return 0;
}