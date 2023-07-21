#include<bits/stdc++.h>
using namespace std;

int n, m, t, k, y, x, ret=0;
int arr[54][54];
int visited[54][54];
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, 1, 0, -1};

void dfs(int y, int x){
   visited[y][x]=1;
   for(int i=0; i<4; i++){
      int ny = y+dy[i];
      int nx = x+dx[i];
      if(ny<0 || ny >= n || nx<0 || nx>=m || !arr[ny][nx])continue;
      if(visited[ny][nx]) continue;
      dfs(ny, nx);
   }
   
}

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>t;
   for(int u=0; u<t; u++){
      cin>>m>>n>>k;
      for(int i=0; i<k; i++){
         cin>>x>>y;
         arr[y][x]=1;
      }

      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if(arr[i][j]==1 && !visited[i][j]) {dfs(i, j); ret++;}
         }
      }
      cout<<ret<<"\n";
      memset(arr, 0, sizeof(arr));
      memset(visited, 0, sizeof(visited));
      ret=0;
   }
   return 0;
}