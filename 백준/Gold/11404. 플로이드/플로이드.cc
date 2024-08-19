#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, cost, from, to;
vector<pair<int, int>> vec[104];
int ret[104][104];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>from>>to>>cost;
        vec[from].push_back({to, cost});
    }

    for(int i=1; i<=n; i++){
        int visited[104];
        fill(&visited[0], &visited[0] + 104, INF);
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        while(pq.size()){
            int cost = -pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            if(visited[pos] < cost) continue;
            for(int j=0; j<vec[pos].size(); j++){
                int new_cost = cost + vec[pos][j].second;
                int new_pos = vec[pos][j].first;
                if(visited[new_pos] > new_cost){
                    visited[new_pos] = new_cost;
                    pq.push({-new_cost, new_pos});
                }
            }
        }
        for(int k=1; k<=n; k++){
            if(i==k) ret[i][k] = 0;
            else if(visited[k] != INF) ret[i][k] = visited[k];
            else ret[i][k] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}