#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

void go(int cnt, int cur){
    if(cnt == 0){
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=cur+1; i<=n; i++){
        vec.push_back(i);
        go(cnt-1, i);
        vec.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    go(m, 0);
    
    return 0;
}