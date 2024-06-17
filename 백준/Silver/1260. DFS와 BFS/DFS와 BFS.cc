#include <bits/stdc++.h>
using namespace std;

int n, m, v, from, to;
vector<int> arr[1004];
int visited[1004];
queue<int> q;

void dfs(int start){       
        visited[start] = 1;
        cout<<start<<" ";
        if(arr[start].size()) sort(arr[start].begin(), arr[start].end());
        for(int i=0; i<arr[start].size(); i++){
            int next = arr[start][i];
            if(visited[next]) continue;
            dfs(next);
        }
}

void bfs(){
    while(q.size()){
        int pos = q.front();
        q.pop();
        sort(arr[pos].begin(), arr[pos].end());
        for(int i=0; i<arr[pos].size(); i++){
            int dest = arr[pos][i];
            if(visited[dest]) continue;
            visited[dest] = 1;
            cout<<dest<<" ";
            q.push(dest);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>v;

    for(int i=0; i<m; i++){
        cin>>from>>to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    dfs(v);

    cout<<"\n";
    fill(&visited[0], &visited[0] + 1004, 0);
    q.push(v);
    visited[v] = 1;
    cout<<v<<" ";
    bfs();
    return 0;
}