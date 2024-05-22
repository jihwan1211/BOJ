#include <bits/stdc++.h>
using namespace std;

int arr[100004];
int dp[100004];
int n;

void go(){
    dp[0] = arr[0];
    int max_sum = dp[0];
    
    for(int i=1; i<n; i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        max_sum = max(max_sum, dp[i]);
    }
    
    cout << max_sum << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    go();
    return 0;
}