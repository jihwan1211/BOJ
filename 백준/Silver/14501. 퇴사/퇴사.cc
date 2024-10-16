#include <bits/stdc++.h>
using namespace std;

int n, t, p;
vector<pair<int, int>> vec;
int dp[16][2];

int solve(int day, int work){
    if(day==n) return 0;
    int &ret = dp[day][work];
    if(ret) return ret;
    if(work == 1){
        if(day + vec[day].first - 1 < n){
            ret = max(ret, solve(day + vec[day].first, 0) + vec[day].second);
            ret = max(ret, solve(day + vec[day].first, 1) + vec[day].second);
        }else {
            ret = -987654321;
        }
    }else {
        ret = max(ret, solve(day + 1, 0));
        ret = max(ret, solve(day + 1, 1));
    }

    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>t>>p;
        vec.push_back({t, p});
    }

    // fill(&dp[0][0], &dp[0][0] + 16*2, -987654321);
    // solve(0, 0);
    // solve(0, 1);
    cout<<max(solve(0, 0), solve(0, 1));
    return 0;
}