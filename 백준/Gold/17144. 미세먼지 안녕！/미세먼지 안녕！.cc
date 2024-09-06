#include <bits/stdc++.h>
using namespace std;

int R, C, T, ret;
int arr[52][52];
int temp[52][52];
vector<pair<int, int>> cleaner;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
const int dy2[] = {0, 1, 0, -1};

void misae_move(){
    fill(&temp[0][0], &temp[0][0] + 52*52, 0);
    int up_y = cleaner[0].first;
    int up_x = cleaner[0].second;
    int down_y = cleaner[1].first;
    int down_x = cleaner[1].second;
    temp[up_y][up_x] = -1;
    temp[down_y][down_x] = -1;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] > 0){
                int y = i;
                int x = j;
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(ny < 0 || ny >=R || nx < 0 || nx >= C) continue;
                    if(arr[ny][nx] == -1) continue;
                    temp[ny][nx] += arr[y][x] / 5;
                    cnt++;
                }
                temp[y][x] += arr[y][x] - ((arr[y][x] / 5)*cnt);
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            arr[i][j] = temp[i][j];
        }
    }
}

void air_clean(){
    int up_y = cleaner[0].first;
    int up_x = cleaner[0].second;
    int down_y = cleaner[1].first;
    int down_x = cleaner[1].second;

    // 위쪽 clean;
    int dir = 0;
    int prev_y = up_y;
    int prev_x = up_x;
    int prev_value = 0;
    while(1){
        int ny = prev_y + dy[dir];
        int nx = prev_x + dx[dir];
        if(ny< 0 || nx >= C || nx < 0){
            dir++;
            continue;
        }
        // 다시 돌아옴
        if(ny == up_y && nx == up_x) break;
        int cur_value = arr[ny][nx];
        arr[ny][nx] = prev_value;
        prev_value = cur_value;
        prev_y = ny;
        prev_x = nx;
    }
    // 아래쪽
    prev_value = 0;
    prev_y = down_y;
    prev_x = down_x;
    dir = 0;
    while(1){
        int ny = prev_y + dy2[dir];
        int nx = prev_x + dx[dir];
        if(ny>= R || nx >= C || nx < 0){
            dir++;
            continue;
        }
        // 다시 돌아옴
        if(ny == down_y && nx == down_x) break;
        int cur_value = arr[ny][nx];
        arr[ny][nx] = prev_value;
        prev_value = cur_value;
        prev_y = ny;
        prev_x = nx;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
            if(arr[i][j] == -1){
                cleaner.push_back({i, j});
            }
        }
    }
    
    for(int i=0; i<T; i++){
        misae_move();
        air_clean();
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] == -1) continue;
            ret += arr[i][j];
        }
    }
    cout<<ret;
    return 0;
}