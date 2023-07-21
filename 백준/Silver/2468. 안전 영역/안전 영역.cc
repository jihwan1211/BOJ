#include<bits/stdc++.h>
using namespace std;

int n, rain, cnt, ret=-1;
int arr[104][104];
int visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
   visited[y][x]=1;
   for(int i=0; i<4; i++){
      int ny = y+dy[i];
      int nx=x+dx[i];
      if(ny<0 || ny>=n || nx<0 || nx>=n || arr[ny][nx]<=rain) continue;
      if(visited[ny][nx]) continue;
      dfs(ny, nx);
   }
}

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>n;
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         cin>>arr[i][j];
      }
   }

   for(int i=0; i<101; i++){
      rain=i;
      memset(visited, 0, sizeof(visited));
      cnt=0;
      for(int j=0; j<n; j++){
         for(int k=0; k<n; k++){
            if(arr[j][k]>rain && !visited[j][k]) {dfs(j, k); cnt++;}
         }
      }
      ret=max(ret, cnt);
   }

   cout<<ret;
   return 0;
}