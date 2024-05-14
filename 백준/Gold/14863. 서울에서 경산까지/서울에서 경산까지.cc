#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, c, d;
int dp[102][100004];
int ret;
vector<pair<int, int>> walk;
vector<pair<int, int>> bike;

void go(){
    // 직전 시간 리스트
    vector<int> vec;
    dp[0][k]=0;
    vec.push_back(k);
    for(int i=1; i<=n; i++){
        int vec_size = vec.size();
        for(int j=0; j<vec_size; j++){
            int prev_time = vec[j];
            // 시간,모금액
            tie(a, b) = walk[i-1];
            tie(c, d) = bike[i-1];
            // 도보 계산
            if(prev_time - a >= 0){
                if(dp[i][prev_time-a]) dp[i][prev_time - a] = max(dp[i][prev_time-a],  dp[i-1][prev_time] + b);
                else {
                    dp[i][prev_time-a] = dp[i-1][prev_time] + b;
                    vec.push_back(prev_time-a);
                }
            }
            // 자전거 계산
            if(prev_time - c >= 0){
                if(dp[i][prev_time-c]) dp[i][prev_time-c] = max(dp[i][prev_time-c], dp[i-1][prev_time] + d);
                else {
                    dp[i][prev_time-c] = dp[i-1][prev_time]+d;
                    vec.push_back(prev_time-c);
                }
            }
        }
        vec.erase(vec.begin(), vec.begin() + vec_size);
    }

    for(int i=0; i<vec.size(); i++){
        ret= max(dp[n][vec[i]], ret);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i=0; i<n; i++){
        // 시간, 모금액
        cin>>a>>b>>c>>d;
        walk.push_back({a, b});
        bike.push_back({c, d});
    }

    go();
    cout<<ret;
    return 0;
}