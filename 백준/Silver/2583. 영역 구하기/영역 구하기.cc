#include<bits/stdc++.h>
using namespace std;

int m, n, k, cnt, space=0;
int arr[104][104];
int visited[104][104];
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, 1, 0, -1};
vector<int> ret;

void dfs(int y, int x){
   visited[y][x]=1;
   space++;
   for(int i=0; i<4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny<0 || ny>=m || nx<0 || nx>=n || !arr[ny][nx]) continue;
      if(visited[ny][nx]) continue;
      dfs(ny, nx);
   }
}

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   fill(&arr[0][0], &arr[0][0]+104*104, 1);
   cin>>m>>n>>k;

   for(int i=0; i<k; i++){
      int rx, ry, lx, ly;
      cin>>lx>>ly>>rx>>ry;
      for(int y=ly; y<ry; y++){
         for(int x=lx; x<rx; x++){
            arr[y][x]=0;
         }
      } 
   }

   for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
         if(arr[i][j] && !visited[i][j]){
            dfs(i, j);
            cnt++;
            ret.push_back(space);
            space=0;
         }
      }
   }
   sort(ret.begin(), ret.end());
   cout<<cnt<<"\n";
   for(int value : ret) cout<<value<<" ";
   return 0;

}