#include<bits/stdc++.h>
using namespace std;

int n, l, r, day;
int arr[52][52];
int visited[52][52];
vector<pair<int, int>> vec[2510];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void print(){
    cout<<"-----------------------\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void dfs(int y, int x, int t){
    visited[y][x]=1;
    vec[t].push_back({y, x});
    for(int i=0; i<4; i++){
        int ny = y +dy[i];
        int nx = x +dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=n)continue;
        if(visited[ny][nx])continue;
        if(abs(arr[y][x] - arr[ny][nx]) >= l && abs(arr[y][x] - arr[ny][nx]) <= r) dfs(ny, nx, t);
    } 
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>l>>r;
    // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

// 로직
    while(1){
        memset(visited, 0, sizeof(visited));
        int team=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]) {
                    dfs(i, j, team);
                    team++;
                }
            }
        }
        if(team != n*n){
    // 다 끝났는지 확인 로직 필요
            day++;
            for(int t=0; t<team; t++){
                int sum=0;
                for(int j=0; j<vec[t].size(); j++){
                    int y, x;
                    tie(y, x) = vec[t][j];
                    sum+=arr[y][x];
                }
                for(int j=0; j<vec[t].size(); j++){
                    int y, x;
                    tie(y, x) = vec[t][j];
                    arr[y][x]=sum/vec[t].size();
                }   
                vec[t].clear();
            }
            // print();
        }else break;
    }
    cout<<day;
    return 0;
}