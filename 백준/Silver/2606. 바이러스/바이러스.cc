#include <bits/stdc++.h>
using namespace std;

int n, conn, from, to, ret;
vector<int> arr[104];
int visited[104];

void dfs(int pos){
    visited[pos] = 1;
    for(int i=0; i<arr[pos].size(); i++){
        int new_pos = arr[pos][i];
        if(visited[new_pos]) continue;
        dfs(new_pos);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>conn;

    for(int i=0; i<conn; i++){
        cin>>from>>to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    dfs(1);
    for(int i=0; i<104; i++) if(visited[i]) ret++;
    cout<<ret-1;
    return 0;
}