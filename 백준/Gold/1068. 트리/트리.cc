#include<bits/stdc++.h>
using namespace std;

vector<int> vec[50];
int n, brk, temp, cnt=0, root;

void go(int a){
    if(a==brk) return;
    if(vec[a].size()){
        for(int i=0; i<vec[a].size(); i++){
            if(vec[a][i] == brk && vec[a].size()==1) { 
                cnt++;
                return;
            }
            if(vec[a][i] == brk) continue;
            go(vec[a][i]);
        }
    }else{
        cnt++;
        return;
    }
    return;
}

void solve(){
    if(brk == root){
        return ;
    }
    if(vec[root].size()){
        for(int j=0; j<vec[root].size(); j++){
            if(vec[root][j] == brk && vec[root].size()==1) { 
                cnt++;
                return;
            }
            go(vec[root][j]);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(temp == -1) {
            root = i;
            continue;
        }
        // temp:부모 i:자식
        vec[temp].push_back(i);
    }
    cin>>brk;
    solve();
    cout<<cnt;
    return 0;
}
    