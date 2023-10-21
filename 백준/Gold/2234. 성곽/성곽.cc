#include<bits/stdc++.h>
using namespace std;

int m, n, roomCnt=0, roomSize=-1, wallRoomSize=-1, temp_room_size=0;
int wall[53][53];
int visited[53][53];

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

void dfs(int y, int x){
    temp_room_size++;
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
        if((wall[y][x] & (1<<i)) || visited[ny][nx]) continue;
        visited[ny][nx]=1;
        // room_size++;
        dfs(ny,nx);
    }
    roomSize=max(roomSize, temp_room_size);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>wall[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]) {
                visited[i][j]=1;
                dfs(i, j);
                roomCnt++;
                temp_room_size=0;
            }
        }
    }
    int roomSizeRet = roomSize;
    roomSize=-1;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                if(wall[i][j]&(1<<k)){
                    memset(visited, 0, sizeof(visited));
                    wall[i][j] &= ~(1<<k);
                    visited[i][j]=1;
                    dfs(i, j);
                    wall[i][j] |=(1<<k);
                    wallRoomSize=max(wallRoomSize, roomSize);
                    temp_room_size=0;
                }
            }
        }
    }
    cout<<roomCnt<<"\n";
    cout<<roomSizeRet<<"\n";
    cout<<wallRoomSize;
    return 0;
}