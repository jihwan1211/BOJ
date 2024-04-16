#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int dp[1000004];
int pos[1000004];

void go(){
    dp[1] = 1;
    pos[1] = 0;
    for(int i=2; i<=1000000; i++){
        if(i%3 == 0 && i%2 == 0){
            dp[i] = min({dp[i/3], dp[i/2], dp[i-1]})+1;
            if(dp[i] == dp[i/3]+1) pos[i] = i/3;
            else if(dp[i] == dp[i/2]+1) pos[i] = i/2;
            else pos[i] = i-1;
        }else if (i%3==0 && i%2 != 0){
            dp[i] = min(dp[i/3], dp[i-1])+1;
            if(dp[i] == dp[i/3]+1) pos[i]= i/3;
            else pos[i] = i-1;
        }else if (i%3 != 0 && i%2 == 0){
            dp[i] = min(dp[i/2], dp[i-1])+1;
            if(dp[i] == dp[i/2]+1) pos[i] = i/2;
            else pos[i] = i-1;
        }else{
            dp[i] = dp[i-1]+1;
            pos[i] = i-1;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    go();
    cout<<dp[n]-1<<"\n";
    while(n != 0){
        cout<<n<<" ";
        n = pos[n];
    }
    return 0;

}