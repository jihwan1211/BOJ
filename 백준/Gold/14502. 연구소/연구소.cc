#include <bits/stdc++.h>
using namespace std;

int N, M, ret=-1;
int arr[9][9];
int visited[9][9];
// 바이러스 저장
vector<pair<int, int>> vec;
vector<pair<int, int>> blank;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny <0 || ny >=N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx] || arr[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

void go(){
    fill(&visited[0][0], &visited[0][0] + 9*9, 0);
    for(int i=0; i<vec.size(); i++){
        if(!visited[vec[i].first][vec[i].second]) dfs(vec[i].first, vec[i].second);
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }

    ret = max(ret, cnt);
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 2) vec.push_back({i, j});
            if(arr[i][j] == 0) blank.push_back({i, j});
        }
    }

    for(int i=0; i<blank.size(); i++){
        for(int j=i+1; j<blank.size(); j++){
            for(int k=j+1; k<blank.size(); k++){
                arr[blank[i].first][blank[i].second] = 1;
                arr[blank[j].first][blank[j].second] = 1;
                arr[blank[k].first][blank[k].second] = 1;
                go();
                arr[blank[i].first][blank[i].second] = 0;
                arr[blank[j].first][blank[j].second] = 0;
                arr[blank[k].first][blank[k].second] = 0;                
            }
        }
    }

    cout<<ret;
    return 0;
}