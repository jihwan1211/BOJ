#include <bits/stdc++.h>
using namespace std;

int arr[104][104][104];
int m, n, h, a, b, c, ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int dh[] = {1, -1};
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> temp;

void bfs(int height, int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
        if(arr[height][ny][nx] == -1 || arr[height][ny][nx] == 1) continue;
        arr[height][ny][nx] = 1;
        temp.push(make_tuple(height, ny, nx));
    }
    for(int i=0; i<2; i++){
        int nh = height + dh[i];
        if(nh < 0 || nh >= h) continue;
        if(arr[nh][y][x] == -1 || arr[nh][y][x] == 1) continue;
        arr[nh][y][x] = 1;
        temp.push(make_tuple(nh, y, x));
    }
}

bool check(){
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

void check2(){
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<"\n";
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m>>n>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>arr[i][j][k];
                if(arr[i][j][k] == 1) q.push(make_tuple(i, j, k));
            }
        }
    }
    
    if(check()) {
        cout<<0;
        return 0;
    }
    while(1){
        while(q.size()){
            tie(a, b, c) = q.front();
            bfs(a, b, c);
            q.pop();
        }
        ret++;
        if(!temp.size()) break;
        while(temp.size()){
            tie(a, b,c) = temp.front();
            q.push(make_tuple(a, b, c));
            temp.pop();
        }
    }
    
    if(check()) cout<<ret-1;
    else cout<<-1;
    
    return 0;
}