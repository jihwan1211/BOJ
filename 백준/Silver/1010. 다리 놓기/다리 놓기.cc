#include <bits/stdc++.h>
using namespace std;

int T, N, M;
long long dp[32][32];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1; i<=30; i++) dp[i][i] = 1;
    for(int i=1; i<=30; i++) dp[1][i] = i;
    for(int i=2; i<=30; i++){
        for(int j=1; j<=30; j++){
            if(i >= j) continue;
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        }
    }
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N>>M;
        cout<<dp[N][M]<<"\n";
    }

    return 0;
}