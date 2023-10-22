#include<bits/stdc++.h>
using namespace std;

int t, n, m, a, b, cnt, num=-1;;
vector<int> vec[1001];
vector<int> friends;
int visited[1004];

void dfs(int here){
    for(int there : vec[here]){
        if(visited[there]) continue;
        visited[there]=1;
        cnt++;
        dfs(there);
    }
}

void decision(){
    if(m==n-1){
        visited[a]=1;
        cnt++;
        dfs(a);
    // for(int i=0; i<friends.size(); i++){
    //     if(!visited[friends[i]]){
    //          cout<<"graph\n";
    //         return;
    //     }
    // }
        if(cnt==n){
            cout<<"tree\n";
            return;
        }else{
            cout<<"graph\n";
            return;
        }
    }else{
        cout<<"graph\n";
        return;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>m;
        for(int j=0; j<m; j++){
            cin>>a>>b;
            // 중복체크?
            vec[a].push_back(b);
            vec[b].push_back(a);
            // friends.push_back(a);
            // friends.push_back(b);
            num=max(num, a);
            num=max(num, b);

        }
        decision();
        memset(visited, 0, sizeof(visited));
        cnt=0;
        for(int k=0; k<=num; k++){
            vec[k].clear();
        }
        num=-1;
    }
    return 0;
}