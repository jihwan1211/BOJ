#include<bits/stdc++.h>
using namespace std;

int row, col, ret=-987654321, dis;
int arr[52][52];
int visited[52][52];
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void bfs(int y, int x){
    memset(visited, 0, sizeof(visited));
    visited[y][x]=1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
            if(visited[ny][nx] || arr[ny][nx]==0) continue;
            visited[ny][nx] = visited[y][x]+1;
            q.push({ny, nx});
            ret=max(ret, visited[ny][nx]);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>row>>col;

    for(int i=0; i<row; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<col; j++){
            if(temp[j]=='W') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]==1) bfs(i, j);
        }
    }
    cout<<ret-1;
    return 0;
}