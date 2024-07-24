#include <bits/stdc++.h>
using namespace std;

int N, M, X, t, ret, from, to;
int dist[1004];
int go[1004];
vector<pair<int, int>> vec[1004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>X;
    for(int i=0; i<M; i++){
        cin>>from>>to>>t;
        vec[from].push_back({to, t});
    }

    for(int i=1; i<=N; i++){
        if(i==X) {
            go[i] = 0;
            continue;
        }
        priority_queue<pair<int, int>> pq;
        pq.push({i, 0});
        fill(&dist[0], &dist[0] + 1004, 987654321);
        while(pq.size()){
            int pos = pq.top().first;
            int cost = -pq.top().second;
            pq.pop();
            if(dist[pos] < cost) continue;
            for(int j=0; j<vec[pos].size(); j++){
                int new_cost = cost + vec[pos][j].second;
                if(new_cost < dist[vec[pos][j].first]){
                    dist[vec[pos][j].first] = new_cost;
                    pq.push({vec[pos][j].first, -new_cost});
                }
            }
        }
       go[i] = dist[X];
    }
    priority_queue<pair<int, int>> pq;
    pq.push({X, 0});
    fill(&dist[0], &dist[0] + 1004, 987654321);
    while(pq.size()){
        int pos = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int j=0; j<vec[pos].size(); j++){
            int new_cost = cost + vec[pos][j].second;
            if(new_cost < dist[vec[pos][j].first]){
                dist[vec[pos][j].first] = new_cost;
                pq.push({vec[pos][j].first, -new_cost});
            }
        }
    }

    for(int i=1; i<=N; i++) ret=max(ret, go[i] + dist[i]);
    cout<<ret;

    return 0;
}