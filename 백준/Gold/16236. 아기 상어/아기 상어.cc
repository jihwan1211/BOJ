#include <bits/stdc++.h>
using namespace std;

// t = 시간(찾고자하는 정답)
int n, t;
int arr[22][22];
int visited[22][22];
int can_eat[22][22];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int sy, sx;
int shark_size = 2;
int eat_cnt =0;
int can_eat_visited = 1e9;

bool bfs(){
    can_eat_visited = 1e9;
    fill(&can_eat[0][0], &can_eat[0][0] + 22*22, 0);
    fill(&visited[0][0], &visited[0][0] + 22*22, 0);
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny <0 || ny>=n || nx<0 || nx>=n) continue;
            if(visited[ny][nx]) continue;
            if(arr[ny][nx] > shark_size) continue;
            if(arr[ny][nx] != 0 && arr[ny][nx] < shark_size) {
                // 먹을 수 있는 후보군에 담음
                can_eat[ny][nx] = visited[y][x] + 1;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
                can_eat_visited = min(can_eat_visited, visited[ny][nx]);
            }
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // can_eat 중 가장 위 가장 왼쪽을 찾는 과정
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(can_eat[i][j] == can_eat_visited){
                // 물고기 먹으러 감
                arr[sy][sx] = 0;
                sy = i;
                sx = j;
                eat_cnt++;
                if(eat_cnt == shark_size){
                    shark_size++;
                    eat_cnt = 0;
                }
                // t += visited[y][x] + 1 - 1;
                t += can_eat_visited-1;
                arr[i][j] = 9;
                return true;
            }
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 9) {
                sy=i;
                sx=j;
            }
        }
    }

    while(1){
        bool isSuccess = bfs();
        if(!isSuccess) break;
    }

    cout<<t;
    return 0;
}