#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
char str;
int arr[54][54];
int visited[54][54];
int dp[54][54];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int go(int y, int x){
    if(dp[y][x]) return dp[y][x];
    
    for(int i=0; i<4; i++){
        int ny = y+dy[i]*arr[y][x];
        int nx = x+dx[i]*arr[y][x];
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(arr[ny][nx]==-1) continue;
        if(visited[ny][nx]) {
            cout<<-1;
            exit(0);
        }
        visited[ny][nx] = 1;
        dp[y][x] = max(dp[y][x], go(ny, nx)+1);
        visited[ny][nx] = 0;
    }
    return dp[y][x];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>str;
            if(str == 'H') arr[i][j]=-1;
            else arr[i][j] = str - '0';
        }
    }
    
    visited[0][0]=1;
    cout<<go(0, 0)+1;
    return 0;
}