#include<bits/stdc++.h>
using namespace std;

int n, m, ret=1000000;
vector<pair<int, int>> c;
vector<pair<int, int>> h;
vector<pair<int, int>> t;

void solve(){
    int distance=0;
    for(int i=0; i<h.size(); i++){
        int td = 1000000;
        for(int j=0; j<t.size(); j++){
            pair<int, int> home = h[i];
            pair<int, int> chic = t[j];
            td = min(abs(home.first - chic.first) + abs(home.second - chic.second), td);
        }
        distance += td;
    }
    ret = min(ret, distance);
}

// 치킨집 고르기
void go(int start){
    if(m == t.size()) {
        solve();
        return;
    }
    else{
        for(int i=start; i<c.size(); i++){
            pair<int, int> a = c[i];
            t.push_back(a);
            go(i+1);
            t.pop_back();
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0 ; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            if(temp==2){
                c.push_back({i, j});
            }
            if(temp==1)h.push_back({i, j});
        }
    }
    go(0);
    cout<<ret;
    return 0;
}