#include <bits/stdc++.h>
using namespace std;

int L[21], J[21], n;
int dp[104];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>L[i];
    }

    for(int i=0; i<n; i++){
        cin>>J[i];
    }


    for(int i=0; i<n; i++){
        for(int hp=100; hp>L[i]; hp--){
            if(hp-L[i]<=0) continue;
            dp[hp] = max(dp[hp], dp[hp-L[i]] + J[i]);
        }
    }

    cout<<dp[100];
    return 0;
}