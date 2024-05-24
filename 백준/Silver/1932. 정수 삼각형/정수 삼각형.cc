#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr[504];
int dp[504][504];

void go(){
    fill(&dp[0][0], &dp[0][0] + 504*504, -1);
    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(dp[i][j] != -1) continue;
            if(j==0) dp[i][j] = dp[i-1][j] + arr[i][j];
            else{
                dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j]) + arr[i][j];
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>temp;
            arr[i].push_back(temp);
        }
    }

    go();
    int ret=-987654321;
    for(int i=0; i<n; i++){
        ret = max(ret, dp[n-1][i]);
    }

    cout<<ret;
    return 0;
}
