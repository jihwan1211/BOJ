#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int arr[504][504];
int visited[504][504];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1}; 
const int dy2[] = {-1, 0, 1, -1, 0, 1, 0, 1, 0, 0, -1, 0};
const int dx2[] = {0, 1, 0, 0, -1, 0, 1, 0, -1, -1, 0, 1};


void go(int y, int x, int cnt, int sum){
    if(cnt >= 4){
        ret = max(ret, sum);
        return;
    }
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx]=1;
        go(ny, nx, cnt+1, sum+arr[ny][nx]);
        visited[ny][nx] = 0;
    }
}

void go2(int y, int x, int start){
    int sum_arr[4] = {start, start, start, start};
    for(int i=0; i<3; i++){
        int ny = y+dy2[i];
        int nx = x+dx2[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) break;
        sum_arr[0] += arr[ny][nx];
    }
    for(int i=3; i<6; i++){
        int ny = y+dy2[i];
        int nx = x+dx2[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) break;
        sum_arr[1] += arr[ny][nx];
    }
    for(int i=6; i<9; i++){
        int ny = y+dy2[i];
        int nx = x+dx2[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) break;
        sum_arr[2] += arr[ny][nx];
    }
    for(int i=9; i<12; i++){
        int ny = y+dy2[i];
        int nx = x+dx2[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) break;
        sum_arr[3] += arr[ny][nx];
    }
    ret = max({ret, sum_arr[0], sum_arr[1], sum_arr[2], sum_arr[3]});
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]=1;
            go(i, j, 1, arr[i][j]);
            go2(i, j, arr[i][j]);
            visited[i][j]=0;
            // fill(&visited[0][0], &visited[0][0]+n*m, 0);
        }
    }

    cout<<ret;
    return 0;
}

