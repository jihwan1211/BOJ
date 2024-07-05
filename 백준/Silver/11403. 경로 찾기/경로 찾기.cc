#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> arr[104];
int ret[104][104];

void dfs(int from, int to){
    ret[from][to] = 1;
    for(int i=0; i<arr[to].size(); i++){
        if(ret[from][arr[to][i]] == 1) continue;
        dfs(from, arr[to][i]);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>temp;
            if(temp == 1){
                arr[i].push_back(j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].size(); j++){
            if(ret[i][arr[i][j]] == 1) continue;
            dfs(i, arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}