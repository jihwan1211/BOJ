#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int N, M, from, to, cost;
vector<pair<int, int>> arr[1004];
int path[1004];
vector<int> path_ret;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>from>>to>>cost;
        arr[from].push_back({to, cost});
    }
    cin>>from>>to;

    priority_queue<pair<int, int>> pq;
    pq.push({0, from});
    int dist[1004];
    fill(&dist[0], &dist[0] + 1004, INF);
    while(pq.size()){
        int pos = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[pos] < cost) continue;
        for(int i=0; i<arr[pos].size(); i++){
            int new_pos = arr[pos][i].first;
            int new_cost = arr[pos][i].second + cost;
            if(dist[new_pos] > new_cost){
                dist[new_pos] = new_cost;
                pq.push({-new_cost, new_pos});
                path[new_pos] = pos;
            }
        }
    }

    // for(int i=0; i<8; i++) cout<<path[i]<<" ";
    // cout<<"\n";
    int p = to;
    while(1){
        // cout<<p<<" ";
        path_ret.push_back(p);
        if(p == from) break;
        p = path[p];
    }

    reverse(path_ret.begin(), path_ret.end());
    cout<<dist[to]<<"\n";
    cout<<path_ret.size()<<"\n";
    for(int i=0; i<path_ret.size(); i++) cout<<path_ret[i]<<" ";

    return 0;
}