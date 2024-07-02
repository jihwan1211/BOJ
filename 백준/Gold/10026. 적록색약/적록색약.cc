#include <bits/stdc++.h>
using namespace std;

int n, normal_ret, sick_ret;
string str;
char arr[104][104];
char char_flag;
int visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0,1, 0, -1};

void normal_dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 ||  ny>=n || nx<0 || nx>=n) continue;
        if(visited[ny][nx]) continue;
        if(arr[ny][nx] == char_flag) normal_dfs(ny, nx);
    }
}

void sick_dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 ||  ny>=n || nx<0 || nx>=n) continue;
        if(visited[ny][nx]) continue;
        if(char_flag == 'R' || char_flag == 'G'){
            if(arr[ny][nx] == 'R' || arr[ny][nx] == 'G') sick_dfs(ny, nx);
        }else{
            if(arr[ny][nx] == char_flag) sick_dfs(ny, nx);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>str;
        for(int j=0; j<str.length(); j++){
            arr[i][j]=str[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]) {
                char_flag = arr[i][j];
                normal_dfs(i, j);
                normal_ret++;
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 104*104, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]) {
                char_flag = arr[i][j];
                sick_dfs(i, j);
                sick_ret++;
            }
        }
    }   

    cout<<normal_ret<<" "<<sick_ret;
    return 0;
}