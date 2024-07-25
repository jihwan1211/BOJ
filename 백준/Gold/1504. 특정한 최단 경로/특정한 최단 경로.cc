#include <bits/stdc++.h>
using namespace std;

int N, E, v1, v2, a, b, c;
long long ret = 987654321;
long long cnt1, cnt2;
long long dist[804];
vector<pair<int, int>> vec[804];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>E;
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    cin>>v1>>v2;
// 1번 -> N번
// 가중치가 있고 음의 가중치는 아니다.
// 다익스트라
// v1 -> v2 -> N의 경우와
// v2 -> v1 -> N의 경우를 중 최단 경로를 찾으면 될듯?
    fill(&dist[0], &dist[0] + 804, 987654321);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});
    dist[1]=0;
    while(pq.size()){
        int pos = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int i=0; i<vec[pos].size(); i++){
            long long new_cost = cost + vec[pos][i].second;
            if(new_cost < dist[vec[pos][i].first]){
                dist[vec[pos][i].first] = new_cost;
                pq.push({-new_cost, vec[pos][i].first}); 
            }
        }
    }
    cnt1+=dist[v1];
    cnt2+=dist[v2];
    fill(&dist[0], &dist[0] + 804, 987654321);
    pq.push({0, v1});
    dist[v1]=0;
    while(pq.size()){
        int pos = pq.top().second;
        long long cost = -pq.top().first;
        
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int i=0; i<vec[pos].size(); i++){
            long long new_cost = cost + vec[pos][i].second;
            if(new_cost < dist[vec[pos][i].first]){
                dist[vec[pos][i].first] = new_cost;
                pq.push({-new_cost, vec[pos][i].first}); 
            }
        }
    }
    cnt1+=dist[v2];
    cnt2+=dist[N];

    fill(&dist[0], &dist[0] + 804, 987654321);
    pq.push({0, v2});
    dist[v2]=0;
    while(pq.size()){
        int pos = pq.top().second;
        long long cost = -pq.top().first;
        
        pq.pop();
        if(dist[pos] < cost) continue;
        for(int i=0; i<vec[pos].size(); i++){
            long long new_cost = cost + vec[pos][i].second;
            if(new_cost < dist[vec[pos][i].first]){
                dist[vec[pos][i].first] = new_cost;
                pq.push({-new_cost, vec[pos][i].first}); 
            }
        }
    }
    cnt1+=dist[N];
    cnt2+=dist[v1];

    ret = min({ret, cnt1, cnt2});     
    if(ret >=987654321) cout<<-1;
    else cout<<ret;
    return 0;
}