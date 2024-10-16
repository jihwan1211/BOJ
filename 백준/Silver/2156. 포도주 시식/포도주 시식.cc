#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10004];
int dp[10004][3];

int solve(int idx, int cnt){
    int &ret = dp[idx][cnt];
    if(idx == n) return 0;
    if(ret != -987654321) return ret;
    if(cnt == 2){
        ret = max(ret, solve(idx+1, 0));
    }else {
        ret = max(ret, solve(idx+1, cnt+1) + arr[idx]);
        ret = max(ret, solve(idx+1, 0));
    }

    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    fill(&dp[0][0], &dp[0][0] + 10004*3, -987654321);
    cout<<solve(0, 0);

    return 0;
}