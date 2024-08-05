#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, parent, child, cost, ret=-1, start;
vector<pair<int, int>> vec[10004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>parent>>child>>cost;
        vec[parent].push_back({child, cost});
        vec[child].push_back({parent, cost});
    }

    
    int dist[10004];
    fill(&dist[0], &dist[0] + 10004, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(pq.size()){
        int pos = pq.top().second;
        int cost = - pq.top().first;
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int j=0; j<vec[pos].size(); j++){
            int there = vec[pos][j].first;
            int new_cost = vec[pos][j].second + cost;
            if(dist[there] > new_cost){
                dist[there] = new_cost;
                pq.push({-new_cost, there});
            }
        }        
    }
       
    for(int j=1; j<=n; j++) {
        if(dist[j] > ret){
            start = j;
            ret=dist[j];
        }
    }
    
    fill(&dist[0], &dist[0] + 10004, INF);
    pq.push({0, start});
    dist[start] = 0;
    while(pq.size()){
        int pos = pq.top().second;
        int cost = - pq.top().first;
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int j=0; j<vec[pos].size(); j++){
            int there = vec[pos][j].first;
            int new_cost = vec[pos][j].second + cost;
            if(dist[there] > new_cost){
                dist[there] = new_cost;
                pq.push({-new_cost, there});
            }
        }        
    }
    for(int j=1; j<=n; j++) {
        if(dist[j] == INF) continue;
        ret=max(ret, dist[j]);        
    }
    cout<<ret;
    return 0;
}