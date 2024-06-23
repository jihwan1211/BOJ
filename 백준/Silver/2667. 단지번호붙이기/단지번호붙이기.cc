#include <bits/stdc++.h>
using namespace std;

int n, ret=1, cnt;
string str;
char arr[27][27];
int visited[27][27];
vector<int> vec;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    cnt++;
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(visited[ny][nx] || arr[ny][nx] == '0') continue;
        visited[ny][nx] = ret;
        dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>str;
        for(int j=0; j<n; j++){
            arr[i][j] = str[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && arr[i][j] != '0'){
                dfs(i, j);
                ret++;
                vec.push_back(cnt);
            }
            cnt=0;
        }
    }

    sort(vec.begin(), vec.end());
    cout<<ret-1<<"\n";
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<"\n";
    return 0;
}
