#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, x, y;
int arr[150];
int visited[150];
int ladder[104];
int snake[104];
queue<int> q;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        ladder[x] = y;
    }

    for(int i=0; i<m; i++){
        cin>>u>>v;
        snake[u]=v;
    }

    q.push(1);
    visited[1] = 1;
    bool flag = false;
    while(q.size()){
        int pos = q.front();
        q.pop();
        
        for(int i=1; i<=6; i++){
            int new_pos = pos + i;
            if(new_pos == 100){
                visited[new_pos] = visited[pos] + 1;
                flag = true;
                break;
            }
            if(new_pos>100) continue;
            if(visited[new_pos]) continue;
            visited[new_pos] = visited[pos] + 1;
            if(ladder[new_pos]){
                new_pos = ladder[new_pos];
                if(visited[new_pos]) visited[new_pos] = min(visited[new_pos], visited[pos] + 1);
                else visited[new_pos] = visited[pos] + 1;
            }
            if(snake[new_pos]){
                new_pos = snake[new_pos];
                if(visited[new_pos]) visited[new_pos] = min(visited[new_pos], visited[pos] + 1);
                else visited[new_pos] = visited[pos] + 1;
            }
            if(new_pos == 100){
                visited[new_pos] = visited[pos] + 1;
                flag = true;
                break;
            }
            q.push(new_pos);
        }
        if(flag) break;
    }

    cout<<visited[100]-1;
    
    return 0;
}