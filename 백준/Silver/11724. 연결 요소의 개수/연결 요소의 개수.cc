#include <bits/stdc++.h>
using namespace std;

int n, m, from, to, ret;
vector<int> arr[1004];
int cnt[1004];
int visited[1004];

void dfs(int from){
    visited[from] = 1;
    for(int i=0; i<arr[from].size(); i++){
        if(visited[arr[from][i]]) continue;
        dfs(arr[from][i]);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>from>>to;
        arr[from].push_back(to);
        arr[to].push_back(from);
        cnt[from] = 1;
        cnt[to] = 1;
    }

    for(int i=0; i<1004; i++){
        if(visited[i]) continue;
        if(cnt[i]){
            dfs(i);
            ret++;
        }
    }

    int temp = 0;
    for(int i=0; i<1004; i++) {
        if(visited[i]) temp++;
    }

    if(m==0) cout<<n;
    else{
        // cout<<ret;
        if(temp == n) cout<<ret;
        else cout<<ret+(n-temp);
    } 
    return 0;
}
