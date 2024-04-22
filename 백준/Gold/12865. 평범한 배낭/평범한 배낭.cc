#include <bits/stdc++.h>
using namespace std;

int n, k, w, v, ret;
vector<pair<int, int>> vec;
int dp[102][100003];

void go(){
    // for(int i=1; i<=n; i++){

    // }
     for(int i=1; i<=n; i++){
         int val = vec[i-1].first;
        // if(i==1){
        //     dp[1][k] = 0;
        //     dp[1][k-vec[0].first] = vec[0].second;
        //     continue;
        // }
        for(int j=0; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-val < 0) {
                // dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j-val] = max(dp[i][j-val], dp[i-1][j] + vec[i-1].second);
            
            
            // if(j-vec[i-1].first < 0) dp[i][j] = dp[i-1][j];
            // else dp[i][j] = max(dp[i-1][j] , dp[i-1][j-vec[i-1].first] + vec[i-1].second);
        }
        
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    
    // fill(&dp[0][0], &dp[0][0]+102*100003, -0);
    for(int i=0; i<n; i++){
        cin>>w>>v;
        vec.push_back({w, v});
    }

    go();
    for(int i=0; i<=k; i++){
        ret = max(ret, dp[n][i]);
    }
    cout<<ret;
    return 0;
}