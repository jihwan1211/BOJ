#include<bits/stdc++.h>
using namespace std;

int n, ret=987654321;
int peo[21];
vector<int> adj[21];
vector<int> team1;
vector<int> team2;
int visited[21];

void team1_dfs(int here){
    for(int there : adj[here]){
        if(find(team1.begin(), team1.end(), there) != team1.end() && !visited[there]){
            visited[there] = 1;
            team1_dfs(there);
        }
    }
}

void team2_dfs(int here){
    for(int there : adj[here]){
        if(find(team2.begin(), team2.end(), there) != team2.end() && !visited[there]){
            visited[there] = 1;
            team2_dfs(there);
        }
    }
}

void go(){    
    visited[team1[0]]=1;
    team1_dfs(team1[0]);
    visited[team2[0]]=1;
    team2_dfs(team2[0]);
    for(int i=0; i<n; i++){
        if(!visited[i]) return;
    }
    int team1_peo =0;
    int team2_peo =0;
    for(int there : team1){
        team1_peo += peo[there];
    }
     for(int there : team2){
        team2_peo += peo[there];
    }
    ret=min(ret, abs(team1_peo - team2_peo));
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>peo[i];
    }

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        for(int j=0; j<num; j++){
            int temp;
            cin>>temp;
            adj[i].push_back(temp-1);
        }
    }

    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i&(1<<j)) team1.push_back(j);
            else team2.push_back(j);
        }
        if(team1.size() && team2.size()) go();
        memset(visited, 0, sizeof(visited));
        team1.clear();
        team2.clear();
    }
    if(ret == 987654321) cout<<-1;
    else cout<<ret;
    return 0;
}