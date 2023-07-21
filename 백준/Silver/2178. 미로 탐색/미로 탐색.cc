#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[104][104];
int visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int sy, int sx){
   visited[sy][sx]=1;
   queue<pair<int, int>> q;
   q.push({sy, sx});
   while(q.size()){
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      for(int i=0; i<4; i++){
         int ny = y + dy[i];
         int nx = x + dx[i];
         if(ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 0) continue;
         if(visited[ny][nx]) continue;
         visited[ny][nx] = visited[y][x] + 1;
         q.push({ny, nx});
         // cout<<ny<<", " <<nx << " : "<<visited[ny][nx]<<"\n";
      }
   }
}

int main(void){
   cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j< M; j++){
            scanf("%1d", &arr[i][j]);
        }
    } 

   bfs(0, 0);
   cout<<visited[N-1][M-1];
   return 0;
}