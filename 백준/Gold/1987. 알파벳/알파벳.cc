#include<bits/stdc++.h>
using namespace std;

int r, c, ret=0, cnt=1;
int arr[21][21];
int alpa[30];
int visited[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};


void go(int y, int x){
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
        if(visited[ny][nx] || alpa[arr[ny][nx]-'A']) continue;
        visited[ny][nx]=1;
        alpa[arr[ny][nx]-'A']=1;
        cnt+=1;
        go(ny,nx);
        cnt-=1;
        visited[ny][nx]=0;
        alpa[arr[ny][nx]-'A']=0;
    }
    ret=max(ret, cnt);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>r>>c;

    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            arr[i][j]=temp[j];
        }
    }
    alpa[arr[0][0]-'A']=1;
    visited[0][0]=1;
    go(0,0);
    cout<<ret;
    return 0;

}