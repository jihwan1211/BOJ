#include <bits/stdc++.h>
using namespace std;

int n, m, from, to;
vector<int> vec[32002];
int inDegree[32002];
int ret[32004];
queue<int> q;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>from>>to;
        vec[from].push_back(to);
        inDegree[to]++;
    }

    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) q.push(i); 
    }

    for(int i=0; i<n; i++){
        // 필요없을듯?
        // if(!q.size()) return;
        int pos = q.front();
        q.pop();

        ret[i] = pos;
        for(int j=0; j<vec[pos].size(); j++){
            int after_student = vec[pos][j];
            inDegree[after_student]--;
            if(inDegree[after_student] <= 0) q.push(after_student);
        }
    }
    for(int i=0; i<n; i++) cout<<ret[i]<<" ";
    return 0;
}