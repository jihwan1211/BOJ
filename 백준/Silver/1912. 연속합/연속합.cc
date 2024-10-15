#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100004], dp[100004];

int solve(){
    dp[0] = arr[0];
    int max_sum = arr[0];

    for(int i=1; i<N; i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    cout<<solve();

    return 0;
}