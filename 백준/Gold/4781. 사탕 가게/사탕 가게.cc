#include <bits/stdc++.h>
using namespace std;

int n, dp[10004];
double m;
vector<pair<int, int>> vec;


int go(int money){
    if(dp[money]) return dp[money];
    for(int i=0; i<vec.size(); i++){
        // dp[money] = (dp[money], dp[money - vec[i].second] + vec[i].first);
        if(money - vec[i].second < 0) continue;
        dp[money] = max(dp[money], go(money - vec[i].second) + vec[i].first);
    }
    return dp[money];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        fill(dp, dp+10004, 0);
        cin>>n>>m;
        if(n == 0) break;
        int m2 = static_cast<int>(m*100.0 + 0.5);
        for(int i=0; i<n; i++){
            int temp;
            double temp2;
            cin>>temp>>temp2;
            int mon = static_cast<int>(temp2*100.0 + 0.5);
            vec.push_back({temp, mon});
        }

        cout<<go(m2)<<"\n";
        vec.clear();
    }
    return 0;
}