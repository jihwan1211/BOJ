#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int arr[104][104];
int visited[104][104];
queue<pair<int, int>> q;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(arr[ny][nx] == 1) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

void check(){
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        int num = 0;
        q.pop();
        for(int j=0; j<4; j++){
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(visited[ny][nx] == 1) num++;
            if(num >= 2){
                arr[y][x] = 0;
                break;
            }
        }
    }
    ret++;
}

void findCheese() {
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 1) q.push({i, j});
        }
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
        }
    }

    while(1){
        findCheese();
        if(!q.size()) break;
        fill(&visited[0][0], &visited[0][0] +104*104, 0);
        dfs(0, 0);
        check();
    }
    cout<<ret;
    
}