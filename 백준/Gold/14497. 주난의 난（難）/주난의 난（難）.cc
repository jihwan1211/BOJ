#include<bits/stdc++.h>
using namespace std;

int r, c, sy, sx, by, bx, ret;
int arr[304][304];
int visited[304][304];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void dfs(int y, int x){
    // cout<<"y : "<<y<<" x : "<<x<<" ret : "<<ret<<"\n";
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
        if(visited[ny][nx]) continue;
        if(arr[ny][nx] == 1) {
            q.push({ny, nx});
            visited[ny][nx]=1;
            continue;
        }else if(arr[ny][nx]==0){
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }else if(arr[ny][nx] == -1){
            ret++;
            cout<<ret;
            exit(0);
            return;
        }
    }
}

void bfs(int y, int x){
    q.push({y, x});
    visited[y][x] =1;
    while(q.size()){
        int qSize = q.size();
        for(int k=0; k<qSize; k++){
            tie(y, x) = q.front();
            q.pop();
            dfs(y, x);
        }
        ret++;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>r>>c>>sy>>sx>>by>>bx;
    sy=sy-1;
    sx=sx-1;
    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            if(temp[j] == '#') arr[i][j] = -1;
            else if(temp[j] == '*') {
                arr[i][j] =2;
            }else if(temp[j]=='1') arr[i][j]=1;
            else arr[i][j]=0;   
        }
    }

    bfs(sy, sx);
    cout<<ret;
    return 0;
}