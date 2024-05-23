#include <bits/stdc++.h>
using namespace std;

int n, r, g, b;
vector<int> arr[1004];
long long dp[1004][3];

long long go(int home, int prevColor) {
    if(home == n-1){
        if(prevColor == 0) return min(arr[home][1], arr[home][2]);
        else if(prevColor == 1) return min(arr[home][2], arr[home][0]);
        else return min(arr[home][0], arr[home][1]);
    }
    long long &ret = dp[home][prevColor];
    if(ret) return ret;
    if(prevColor == 0) ret += min(go(home+1, 1) + arr[home][1], go(home+1, 2) + arr[home][2]);
    else if(prevColor == 1) ret += min(go(home+1, 2) + arr[home][2], go(home+1, 0)+arr[home][0]);
    else ret += min(go(home+1, 0)+arr[home][0], go(home+1, 1)+arr[home][1]);
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>r>>g>>b;
        arr[i].push_back(r);
        arr[i].push_back(g);
        arr[i].push_back(b);
    }
    
    cout<<min({go(1, 0) + arr[0][0], go(1, 1) + arr[0][1], go(1, 2) + arr[0][2]});
    return 0;
}