#include <bits/stdc++.h>
using namespace std;
# define INF 1e9

int N, M, from, to, cost;
vector<pair<int, int>> vec[1004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>from>>to>>cost;
        vec[from].push_back({to, cost});
    }
    cin>>from>>to;

    int dist[1004];
    fill(&dist[0], &dist[0] + 1004, INF);
    priority_queue<pair<int, int>> pq;

    dist[from] = 0;
    pq.push({0, from});
    while(pq.size()){
        int pos = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int i=0; i<vec[pos].size(); i++){
            int there = vec[pos][i].first;
            int new_cost = cost + vec[pos][i].second;
            if(dist[there] > new_cost){
                dist[there] = new_cost;
                pq.push({-new_cost, there});
            }
        }
    }

    cout<<dist[to];
    return 0;
}
