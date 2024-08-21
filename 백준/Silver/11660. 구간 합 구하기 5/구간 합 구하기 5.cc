#include <bits/stdc++.h>
using namespace std;

int arr[1026][1026];
int dp[1026][1026];
int pos1y, pos1x, pos2y, pos2x, n, m;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        cin>>pos1y>>pos1x>>pos2y>>pos2x;
        cout<<dp[pos2y][pos2x] - dp[pos2y][pos1x-1] - dp[pos1y-1][pos2x] + dp[pos1y-1][pos1x-1]<<"\n";
    }

    return 0;
}

