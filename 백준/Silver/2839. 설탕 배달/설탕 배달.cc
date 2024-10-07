#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int N;
int dp[5004];

int go(int weight){
    int &ret = dp[weight];
    if(ret != INF) return ret;
    if(weight == 0) return 0;
    if(weight-5 >= 0) ret = min(ret, go(weight-5) + 1);
    if(weight-3 >= 0) ret = min(ret, go(weight -3) + 1);
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    queue<pair<int, int>> q;
    q.push({N, 0});

    fill(&dp[0], &dp[0] + 5004, INF);
    int ret = go(N);
    if(ret == INF) cout<<-1;
    else cout<<ret;
    return 0;
}