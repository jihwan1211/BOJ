#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c, s, ret=987654321;
int rel[51][51];
int arr[51][51];
int visited[51][51];
vector<tuple<int, int, int>> vec;
vector<int> temp;


const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void print2(){
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<"\n";
    
}

void rotate(int index, int left_x, int left_y, int right_x, int right_y){
    temp.clear();
    memset(visited, 0, sizeof(visited));
    // tie(r, c, s) = vec[index];
    // int left_x = r-s;
    // int left_y = c-s;
    // int right_x = r+s;
    // int right_y = c+s;

    int nx = left_x;
    int ny = left_y;
    while(nx <= right_x){
        if(visited[ny][nx]) {
            ny = ny + dy[0];
            nx = nx + dx[0];
            continue;
        }
        visited[ny][nx]=1;
        temp.push_back(arr[ny][nx]);
        if(nx + dx[0] > right_x) break;
        ny = ny + dy[0];
        nx = nx + dx[0];
    }
    while(ny <= right_y){
         if(visited[ny][nx]) {
            ny = ny + dy[1];
            nx = nx + dx[1];
            continue;
        }
        visited[ny][nx]=1;
        temp.push_back(arr[ny][nx]);
        if(ny + dy[1] > right_y) break;
        ny = ny + dy[1];
        nx = nx + dx[1];
    }
    while(nx >= left_x){
        if(visited[ny][nx]) {
            ny = ny + dy[2];
            nx = nx + dx[2];
            continue;
        }
        visited[ny][nx]=1;
        temp.push_back(arr[ny][nx]);
        if(nx + dx[2] < left_x) break;
        ny = ny + dy[2];
        nx = nx + dx[2];
    }
    while(ny > left_y){
        if(visited[ny][nx]) {
            ny = ny + dy[3];
            nx = nx + dx[3];
            continue;
        }
        visited[ny][nx]=1;
        temp.push_back(arr[ny][nx]);
        if(ny + dy[3] < left_y) break;
        ny = ny + dy[3];
        nx = nx + dx[3];
    }
    // print2();
    nx = left_x + 1;
    ny = left_y;
    memset(visited, 0, sizeof(visited));
    int i=0;
    while(nx <= right_x){
        if(visited[ny][nx]) {
            ny = ny + dy[0];
            nx = nx + dx[0];
            continue;
        }
        visited[ny][nx]=1;
        arr[ny][nx] = temp[i++];
        // temp.push_back(arr[ny][nx]);
        if(nx + dx[0] > right_x) break;
        ny = ny + dy[0];
        nx = nx + dx[0];
    }
    while(ny <= right_y){
         if(visited[ny][nx]) {
            ny = ny + dy[1];
            nx = nx + dx[1];
            continue;
        }
        visited[ny][nx]=1;
        // temp.push_back(arr[ny][nx]);
        arr[ny][nx] = temp[i++];
        if(ny + dy[1] > right_y) break;
        ny = ny + dy[1];
        nx = nx + dx[1];
    }
    while(nx >= left_x){
        if(visited[ny][nx]) {
            ny = ny + dy[2];
            nx = nx + dx[2];
            continue;
        }
        visited[ny][nx]=1;
        // temp.push_back(arr[ny][nx]);
        arr[ny][nx] = temp[i++];
        if(nx + dx[2] < left_x) break;
        ny = ny + dy[2];
        nx = nx + dx[2];
    }
    while(ny >= left_y){
        if(visited[ny][nx]) {
            ny = ny + dy[3];
            nx = nx + dx[3];
            continue;
        }
        visited[ny][nx]=1;
        // temp.push_back(arr[ny][nx]);
        arr[ny][nx] = temp[i++];
        if(ny + dy[3] < left_y) break;
        ny = ny + dy[3];
        nx = nx + dx[3];
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>rel[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin>>r>>c>>s;
        vec.push_back(make_tuple(r-1, c-1, s));
    }
    sort(vec.begin(), vec.end());
    do{
        memcpy(arr, rel, sizeof(arr));
    for(int t=0; t<k; t++){
        tie(r, c, s) = vec[t];
        int left_x = c-s;
        int left_y = r-s;
        int right_x = c+s;
        int right_y = r+s;
        while(1){
            if(left_x == right_x || left_y == right_y) break;
            rotate(t, left_x, left_y, right_x, right_y);
            left_x++;
            left_y++;
            right_x--;
            right_y--;
        }
        // print();
        // cout<<"\n---\n";
    }

    // print();

    for(int i=0; i<n; i++){
        int num=0;
        for(int j=0; j<m; j++){
            num+=arr[i][j];
        }
        ret=min(ret, num);
    }
    }while(next_permutation(vec.begin(), vec.end()));
    cout<<ret;
    return 0;
}