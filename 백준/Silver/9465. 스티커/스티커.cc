#include <bits/stdc++.h>
using namespace std;

int TC, n;
int arr[2][100004];

void go(){
    int dp[2][100004][2];
    dp[0][0][0] = 0;
    dp[0][0][1] = arr[0][0];
    dp[1][0][0] = 0;
    dp[1][0][1] = arr[1][0];
    for(int i=1; i<n; i++){
        dp[0][i][0] = max({dp[0][i-1][0], dp[0][i-1][1], dp[1][i-1][0], dp[1][i-1][1]}); 
        dp[0][i][1] = max({dp[0][i-1][0], dp[1][i-1][0], dp[1][i-1][1]}) + arr[0][i];
        dp[1][i][0] = max({dp[0][i-1][0], dp[0][i-1][1], dp[1][i-1][0], dp[1][i-1][1]}); 
        dp[1][i][1] = max({dp[0][i-1][0], dp[0][i-1][1], dp[1][i-1][0]}) + arr[1][i];
    }
     
    cout<<max({dp[0][n-1][0], dp[0][n-1][1], dp[1][n-1][0], dp[1][n-1][1]})<<"\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>TC;
    for(int i=0; i<TC; i++){
        cin>>n;
        for(int j=0; j<2; j++){
            for(int k=0; k<n; k++){
                cin>>arr[j][k];
            }
        }
        go();
        fill(&arr[0][0], &arr[0][0] + 100004*2, 0);
    }

    return 0;
}