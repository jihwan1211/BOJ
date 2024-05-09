#include <bits/stdc++.h>
using namespace std;

int n;
int arr[104];
long long dp[104][24];

void go(){
    dp[0][arr[0]] = 1;
    for(int i=1; i<n-1; i++){
        for(int j=0; j<21; j++){
            if(dp[i-1][j]){
                int temp_plus_val = j+arr[i];
                int temp_minus_val = j-arr[i];
                if(temp_plus_val >= 0 && temp_plus_val <=20) dp[i][temp_plus_val] += dp[i-1][j];
                if(temp_minus_val >= 0 && temp_minus_val <=20) dp[i][temp_minus_val] += dp[i-1][j];
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // dfs(arr[0], 0);
    go();
    
    cout<<dp[n-2][arr[n-1]];
    return 0;
}