#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, r, from, to, cost, ret=-1;
vector<pair<int, int>> vec[104];
int arr[104];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>r;
    for(int i=1; i<=n; i++) cin>>arr[i];

    for(int i=0; i<r; i++){
        cin>>from>>to>>cost;
        vec[from].push_back({to, cost});
        vec[to].push_back({from, cost});
    }

    priority_queue<pair<int, int>> pq;
    int dist[104];
    for(int i=1; i<=n; i++){
        fill(&dist[0], &dist[0] + 104, INF);
        dist[i] = 0;
        pq.push({0, i});
        while(pq.size()){
            int pos = pq.top().second;
            int cost = - pq.top().first;
            pq.pop();
            if(dist[pos] < cost) continue;
            for(int j=0; j<vec[pos].size(); j++){
                int new_pos = vec[pos][j].first;
                int new_cost = cost + vec[pos][j].second;
                if(new_cost < dist[new_pos]){
                    dist[new_pos]=new_cost;
                    pq.push({-new_cost, new_pos});
                }
            }
        }
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(dist[j] <= m) cnt+= arr[j];
        }
        ret = max(ret, cnt);
    }
    
    cout<<ret;
    return 0;
}