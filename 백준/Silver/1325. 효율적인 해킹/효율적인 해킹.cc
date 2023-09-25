#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10004];
vector<int> a;
int visited[10004];
int ans[10004];
int n, m, ret=0, cnt=0;

void dfs(int here){
    visited[here] = 1;
    for(int there: adj[here]){
        if(visited[there]) continue;
        cnt++;
        dfs(there);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        memset(visited, 0, sizeof(visited));
        cnt=0;
        dfs(i);
        ret = max(ret, cnt);
        ans[i]=cnt;
    }
    for(int i=1; i<=n; i++){
        if(ans[i]==ret) a.push_back(i);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
    return 0;
}