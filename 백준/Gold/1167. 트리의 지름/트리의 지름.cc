#include <bits/stdc++.h>
using namespace std;

int V, V_from, V_to, distan, ret = -1;
vector<pair<int, int>> arr[100004];
int visited[100004];
int end_pos, new_pos;


void go(int from, int sum){
    visited[from] = 1;
    if(ret < sum){
        ret = sum;
        new_pos = from;
    }
    for(int i=0; i<arr[from].size(); i++){
        int to = arr[from][i].first;
        if(visited[to]) continue;
        go(to, sum+arr[from][i].second);
    }
    visited[from] = 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V;
    for(int i=1; i<=V; i++){
        cin>>V_from;
        while(1){
            cin>>V_to;
            if(V_to == -1) break;
            cin>>distan;
            arr[V_from].push_back({V_to, distan});
        }
    }

    for(int i=1; i<=100000; i++){
        if(arr[i].size() == 1) {
            end_pos = i;
            break;
        }
    }

    go(end_pos, 0);
       
    go(new_pos, 0);
    
    cout<<ret;
    return 0;
}