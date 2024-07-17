#include <bits/stdc++.h>
using namespace std;

int start_x, start_y, cnt, N, M;
char arr[604][604];
int visited[604][604];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};


void dfs(int y, int x){
    visited[y][x] = 1;
    if(arr[y][x] == 'P') cnt++;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i]; 
        if(ny < 0 || ny>=N || nx<0 || nx >=M) continue;
        if(visited[ny][nx] || arr[ny][nx] == 'X') continue;
        dfs(ny, nx);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'I'){
                start_y = i;
                start_x = j;
            }
        }
    }

    dfs(start_y, start_x);
    if(cnt) cout<<cnt;
    else cout<<"TT";
    return 0;
}