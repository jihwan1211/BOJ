#include <bits/stdc++.h>
using namespace std;

int n;
int dp[50004];

int go(int target){
    int &ret = dp[target];
    if(ret != 987654321) return ret;
    for(int i=1; i<=240; i++){
        int num = pow(i, 2);
        if(num > target/2) break;
        if(num > 50000) break;
        ret = min(ret, go(num) + go(target-num));
    }
    
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    fill(&dp[0], &dp[50004], 987654321);
    dp[1] = 1;
    for(int i=2; i<=240; i++){
        int num = pow(i, 2);
        if(num > 50000) break;
        dp[num] = 1;
    }

    cout<<go(n);
    return 0;
}