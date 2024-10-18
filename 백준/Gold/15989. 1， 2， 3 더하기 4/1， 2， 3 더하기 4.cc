#include <bits/stdc++.h>
using namespace std;

long long dp[10004][4];
int n, t;

void solve(){
    for(int i=1; i<=10000; i++) dp[i][1] = 1;
    for(int i=2; i<=10000; i++){
        int a = i/2;
        int b = i/3;
        int c = i%3;
        dp[i][2] = a;
        long long cnt = 0;
        // 3을 계산
        for(int j=1; j<=b; j++){
            int d = i-(j*3);
            if(d == 0) break;
            cnt += dp[d][1] + dp[d][2];
        }
        if(c == 0) cnt++;
        dp[i][3] = cnt;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    solve();
    for(int i=0; i<t; i++){
        cin>>n;
        cout<<dp[n][1] + dp[n][2] + dp[n][3]<<"\n";
    }

    return 0;
}