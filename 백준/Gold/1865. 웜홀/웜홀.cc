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
        
        int dist[504];
        fill(&dist[0], &dist[0] + 504, 0);
        bool negative = false;
        // 임의의 출발지점 N+1 정의 및 모든 정점들과 N+1을 연결
        int start=N+1;
        for(int j=1; j<=N; j++) vec[start].push_back({j, 0});
        dist[start] = 0;
        // N-1번의 라운드 진행
        for(int k=1; k<=N; k++){
            // N개의 모든 정점에서 확인
            for(int l=1; l<=N; l++){
                for(int m=0; m<vec[l].size(); m++){
                    int there = vec[l][m].first;
                    int cost = vec[l][m].second;
                    if(dist[l] != 987654321 && dist[there] > dist[l] + cost){
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