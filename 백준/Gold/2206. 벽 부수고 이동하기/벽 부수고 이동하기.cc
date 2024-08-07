#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

string str;
int N, M, ret=INF;
int arr[1004][1004];
int visited[1004][1004][2];
vector<pair<int, int>> vec;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(){
    visited[0][0][0] = 1;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});

    while(q.size()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int isBroken = q.front().second;
        q.pop();
        if(y==N-1 && x==M-1){
            ret=visited[y][x][isBroken];
            break;
        }
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            if(visited[ny][nx][isBroken]) continue;
            if(arr[ny][nx] == 1) {
                if(isBroken) continue;
                else {
                    visited[ny][nx][1] = visited[y][x][isBroken] + 1;
                    q.push({{ny, nx}, 1});
                }
            }else {
                visited[ny][nx][isBroken] = visited[y][x][isBroken] + 1;
                q.push({{ny, nx}, isBroken});
            }
            
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j]-'0';
            if(arr[i][j] == 1) vec.push_back({i, j});
        }
    }

    bfs();

    if(ret == INF) cout<<-1;
    else cout<<ret;
    return 0;
}