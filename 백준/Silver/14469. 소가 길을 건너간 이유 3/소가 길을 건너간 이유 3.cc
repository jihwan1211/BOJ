#include <bits/stdc++.h>
using namespace std;

int n, a, b, t;
vector<pair<int, int>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++){
        if(t <= vec[i].first){
            t=vec[i].first+vec[i].second;
        }else{
            t+=vec[i].second;
        }
    }
    cout<<t;
    return 0;
}