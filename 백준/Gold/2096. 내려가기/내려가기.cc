#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int arr[100000][3];
int prevDp[3];
int dp[3];
int N, maxRet = -1, minRet = INF;

void goMax(){
    dp[0] = arr[0][0];
    dp[1] = arr[0][1];
    dp[2] = arr[0][2];
    for(int i=1; i<N; i++){
        prevDp[0] = dp[0];
        prevDp[1] = dp[1];
        prevDp[2] = dp[2];
        for(int j=0; j<3; j++){
            if(j==0) dp[j] = max(prevDp[0], prevDp[1]) + arr[i][j];
            else if (j==1) dp[j] = max({prevDp[0], prevDp[1], prevDp[2]}) + arr[i][j];
            else dp[j] = max(prevDp[1], prevDp[2]) + arr[i][j];
        }
    }
    
    for(int i=0; i<3; i++) maxRet = max(maxRet, dp[i]);
}

void goMin(){
    dp[0] = arr[0][0];
    dp[1] = arr[0][1];
    dp[2] = arr[0][2];
    for(int i=1; i<N; i++){
        prevDp[0] = dp[0];
        prevDp[1] = dp[1];
        prevDp[2] = dp[2];
        for(int j=0; j<3; j++){
            if(j==0) dp[j] = min(prevDp[0], prevDp[1]) + arr[i][j];
            else if (j==1) dp[j] = min({prevDp[0], prevDp[1], prevDp[2]}) + arr[i][j];
            else dp[j] = min(prevDp[1], prevDp[2]) + arr[i][j];
        }
    }

    for(int i=0; i<3; i++) minRet = min(minRet, dp[i]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    goMax();
    fill(&dp[0], &dp[0]+3, 0);
    goMin();

    cout<<maxRet<<" "<<minRet;
    return 0;
}