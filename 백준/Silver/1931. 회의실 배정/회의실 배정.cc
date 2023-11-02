#include <bits/stdc++.h>
using namespace std;

int a, b, n, ret, start, endd;
vector<pair<int, int>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        vec.push_back({b, a});
    }
    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++){
        tie(a, b) = vec[i];
        if(!start && !endd) {
            endd=a;
            start=b;
            ret++;
            continue;
        }
        if(b >= endd){
            endd=a;
            ret++;
        }
        // cout<<i<<" "<<ret<<"\n";
    }

    // cout<<"\n------\n";
    // for(int i=0; i<n; i++){
    //     tie(a, b) = vec[i];
    //     cout<<a<<" "<<b<<"\n";
    // }
    cout<<ret;
    return 0;
}