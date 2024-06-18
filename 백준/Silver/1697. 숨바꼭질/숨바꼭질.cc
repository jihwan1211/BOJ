#include <bits/stdc++.h>
using namespace std;

int from, to;
int visited[100004];
queue<int> q;

int bfs(){
    while(q.size()){
        int start = q.front();
        if(start == to) return visited[start]-1;
        q.pop();
        if(start-1 >= 0 && !visited[start-1]){
            visited[start-1] = visited[start] + 1;    
            q.push(start-1);        
        } 
        if(start+1 <= 100000 && !visited[start+1]){
            visited[start+1] = visited[start] + 1;    
            q.push(start+1);        
        } 
        if(start*2 <= 100000 && !visited[start*2]){
            visited[start*2] = visited[start] + 1;    
            q.push(start*2);        
        } 
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>from>>to;
    q.push(from);
    visited[from] = 1;
    cout<<bfs();
    return 0;
}
