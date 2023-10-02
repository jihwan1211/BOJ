#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int r, c, ret;
int arr[1004][1004];
int visited[1004][1004];
int fire[1004][1004];
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, 1, 0, -1};
int sy, sx;
queue<pair<int, int>> q2;

void print(){
    cout<<"----\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void print2(){
    cout<<"----\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<fire[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void bfs(int y, int x){
    queue<pair<int, int>> q1;
    q1.push({y, x});
    while(q1.size()){
        tie(y, x) = q1.front();
        q1.pop();
        if(x == c- 1 || y == r - 1 || x == 0 || y == 0){
            ret = visited[y][x];
            break;
		}
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
            if(visited[ny][nx] || arr[ny][nx]==-1 || arr[ny][nx]==2)continue;
            if(fire[ny][nx] <= visited[y][x]+1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q1.push({ny, nx});
        }
    }
}

void bfs2(){
    int y, x;
    while(q2.size()){
        tie(y, x) = q2.front();
        q2.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
            if(fire[ny][nx] != INF || arr[ny][nx]==-1) continue;
            fire[ny][nx] = fire[y][x]+1;
            q2.push({ny, nx});
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
    cin>>r>>c;
    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<temp.size(); j++){
            if(temp[j] == '#') arr[i][j]=-1;
            else if(temp[j] == '.') arr[i][j]=0;
            else if(temp[j] =='J') {
                arr[i][j]=1;
                sy=i;
                sx=j;
                visited[i][j]=1;
            }
            else {
                arr[i][j] =2;
                q2.push({i, j});
                fire[i][j]=1;
            }
        }
    }

    
    bfs2();
    bfs(sy, sx);
    
    if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
	return 0;
    // print();
    // print2();
}