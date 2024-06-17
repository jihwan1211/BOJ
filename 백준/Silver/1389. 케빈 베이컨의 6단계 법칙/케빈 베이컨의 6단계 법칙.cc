#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> arr[104];
int ret[104];
int visited[104];
queue<int> q;

void bfs(){
    while(q.size()){
        int pos = q.front();
        q.pop();
        for(int i=0; i<arr[pos].size(); i++){
            int dest = arr[pos][i];
            if(visited[dest]) continue;
            visited[dest] = visited[pos]+1;
            q.push(dest);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        q.push(i);
        bfs();
        int temp = 0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            temp += visited[j];
        }
        ret[i] = temp;
        fill(&visited[0], &visited[0] + 104, 0);
    }

    int res = 1;
    for(int i=2; i<=n; i++){
        if(ret[res] > ret[i]){
            res = i;
        }
    }

    cout<<res;
    return 0;
}