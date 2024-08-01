#include <bits/stdc++.h>
using namespace std;

int TC, N, M, W, S, E, T;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>TC;
    for(int i=0; i<TC; i++){
        cin>>N>>M>>W;
        vector<pair<int, int>> vec[504];
        for(int j=0; j<M; j++){
            cin>>S>>E>>T;
            vec[S].push_back({E, T});
            vec[E].push_back({S, T});
        }
        for(int j=0; j<W; j++){
            cin>>S>>E>>T;
            vec[S].push_back({E, -T});
        }
        bool success = false;
        int dist[504];
        fill(&dist[0], &dist[0] + 504, 987654321);
        bool negative = false;
        // 출발 지점이 j인 상황
        dist[1] = 0;
        // N-1번의 라운드 진행
        for(int k=1; k<=N; k++){
            // N개의 모든 정점에서 확인
            for(int l=1; l<=N; l++){
                for(int m=0; m<vec[l].size(); m++){
                    int there = vec[l][m].first;
                    int cost = vec[l][m].second;
                    if(dist[there] > dist[l] + cost){
                        if(k == N) {
                            negative = true;
                            break;
                        }
                        dist[there] = dist[l] + cost;
                    }
                }
            }
        }
        if(negative) {
            cout<<"YES\n";
        }else cout<<"NO\n";
    }

    return 0;
}