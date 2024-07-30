#include <bits/stdc++.h>
using namespace std;

int V, E, start, u, v, w;
vector<pair<int, int>> vec[20004];
int dist[20004];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;
    cin>>start;
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        vec[u].push_back({v, w});
    }

    fill(&dist[0], &dist[0] + 20004, 987654321);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(pq.size()){
        int pos = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int i=0; i<vec[pos].size(); i++){
            int new_pos = vec[pos][i].first;
            int new_cost = cost + vec[pos][i].second;
            if(new_cost < dist[new_pos]){
                dist[new_pos] = new_cost;
                pq.push({-new_cost, new_pos});
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if(dist[i] == 987654321) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    return 0;
}