#include<bits/stdc++.h>
using namespace std;

int r, c, k, ret;
int arr[10][10];
int visited[10][10];
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, 1, 0, -1};

vector<int> vec;

void dfs(int y, int x){
    // cout<<y<<" "<<x<<"\n";
    if(y==0 && x==c-1){
        vec.push_back(visited[0][c-1]);
        // visited[0][c-1]=0;
        return;
        // 종료조건
    }
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
        if(visited[ny][nx] || arr[ny][nx])continue;
        visited[ny][nx] = visited[y][x] + 1;
        dfs(ny, nx);
        visited[ny][nx] = 0;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>r>>c>>k;

    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            if(temp[j] == '.') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    
    visited[r-1][0]=1;
    dfs(r-1, 0);
    for(int i=0; i<vec.size(); i++){
        if(vec[i]==k)ret++;
    }
    cout<<ret;
    return 0;
}