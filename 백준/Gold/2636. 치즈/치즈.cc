#include<bits/stdc++.h>
using namespace std;

int arr[104][104];
int arr2[104][104];
int visited[104][104];
int row, col, t=0;
int cur_c=0, prev_c=0;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0 || ny >= row || nx < 0 || nx >= col || visited[ny][nx]) continue;
        if(arr[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

void func(int i, int j){
     for(int k =0; k<4; k++){
        int ny = i + dy[k];
        int nx = j + dx[k];
        if(ny < 0 || ny >= row || nx < 0 || nx >= col) continue;
        if(visited[ny][nx] == 1) {
            arr[i][j] = 0;
            cur_c--;
            return;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>row>>col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) cur_c++;
        }
    }
    while(cur_c){
        t++;
        prev_c = cur_c;
        memset(visited, 0, sizeof(visited));
        dfs(0,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j] == 1) {
                    func(i, j);
                }
            }
        }
    }
    cout<<t<<"\n"<<prev_c;
    return 0;
}
    