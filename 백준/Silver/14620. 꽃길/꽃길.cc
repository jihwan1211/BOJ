#include<bits/stdc++.h>
using namespace std;

int n, ret=987654321;
int arr[12][12];
int visited[12][12];
const int dy[]={-1, 0, 1, 0};
const int dx[]={0, 1, 0, -1};
vector<pair<int, int>> vec;

void print(vector<pair<int, int>> b){
    for(int i=0; i<b.size(); i++){
        int y, x;
        tie(y, x) = b[i];
        cout<<"y : "<<y<<"x : "<< x <<"\n";
    }
    cout<<"\n";
}

void go(vector<pair<int, int>> b){
    memset(visited, 0, sizeof(visited));
    int cost=0;
    for(int j=0; j<b.size(); j++){
        int y,x;
        tie(y, x) = b[j];
        cost+=arr[y][x];
        if(visited[y][x]) return;
        visited[y][x]=1;
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(visited[ny][nx]) return;
            cost+=arr[ny][nx];
            visited[ny][nx]=1;
        }
    }
    // cout<<cost<<"\n";
    ret=min(ret, cost);
}

void combi(int start, vector<pair<int, int>> b){
    if(b.size() == 3){
        go(b);
        // print(b);
        return;
    }
    for(int i=start+1; i<vec.size(); i++){
        b.push_back(vec[i]);
        combi(i, b);
        b.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if( i==0 || j==0 || i==n-1 || j==n-1) continue;
            vec.push_back({i, j});
        }
    }

    vector<pair<int, int>> b;
    combi(-1, b);
    
    cout<<ret;
    return 0;

}