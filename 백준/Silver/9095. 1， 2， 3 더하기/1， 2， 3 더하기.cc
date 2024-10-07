#include <bits/stdc++.h>
using namespace std;
int N, T;
int dp[14];

void go(){
    for(int i=4; i<=11; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    go();
    for(int i=0; i<T; i++){
        cin>>N;
        cout<<dp[N]<<"\n";
    }
    return 0;
}