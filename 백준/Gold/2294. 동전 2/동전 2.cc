#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> vec;
int dp[10004];
int coin[100004];

void go(){
    // 돈의 범위
    for(int i=1; i<=k; i++){
        if(coin[i]) dp[i] = 1;
        else {
            // j 내가 가지고 있는 돈
            for(int j=0; j<vec.size(); j++){
                if(vec[j] > i) break;
                if(dp[i-vec[j]] == -1) continue;
                if(dp[i]) dp[i] = min(dp[i], dp[vec[j]] + dp[i-vec[j]]);
                else dp[i] = dp[vec[j]] + dp[i-vec[j]];
            }
            if(!dp[i]) dp[i] = -1;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        coin[temp]=1;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    go();
    cout<<dp[k];
    return 0;
}