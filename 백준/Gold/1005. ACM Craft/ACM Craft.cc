#include <bits/stdc++.h>
using namespace std;

int T, N, K, W, ret=-1;
int build_t[1004];
int inDegree[1004];
vector<int> arr[1004];

int go(){
    queue<int> q;
    int dp[1004];
    fill(&dp[0], &dp[0] + 1004, 0);
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0) {
            q.push(i);
            dp[i] = build_t[i];
        }
    }
    
    while(q.size()){
        int pos = q.front();
        q.pop();
        for(int i=0; i<arr[pos].size(); i++){
            int new_pos = arr[pos][i];
            dp[new_pos] = max(dp[new_pos], dp[pos] + build_t[new_pos]);
            if(inDegree[new_pos] == 1){
                q.push(new_pos);
            }
            inDegree[new_pos]--;
        }
    }
    return dp[W];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;

    for(int i=0; i<T; i++){
        // 건물개수 규칙개수
        cin>>N>>K;
        for(int j=1; j<=N; j++) cin>>build_t[j];
        for(int j=0; j<K; j++){
            int first_build, later_build;
            cin>>first_build>>later_build;
            arr[first_build].push_back(later_build);
            inDegree[later_build]++;
        }
        cin>>W;
        cout<<go()<<"\n";
        fill(&build_t[0], &build_t[0] + 1004, -1);
        for(int j=1; j<=N; j++){
            arr[j].clear();
        }
    }
}