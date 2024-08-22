#include <bits/stdc++.h>
using namespace std;

int N, node1, node2;
vector<int> arr[100004];
int visited[100004];

// pos가 부모, new_pos가 자식
void dfs(int parent, int children){
    visited[children] = parent;
    for(int i=0; i<arr[children].size(); i++){
        int new_pos = arr[children][i];
        if(visited[new_pos]) continue;
        dfs(children, new_pos);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N-1; i++){
        cin>>node1>>node2;
        arr[node1].push_back(node2);
        arr[node2].push_back(node1);
    }

    dfs(1, 1);
    for(int i=2; i<=N; i++){
        cout<<visited[i]<<"\n";
    }

    return 0;
}

