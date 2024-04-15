#include <bits/stdc++.h>
using namespace std;
int n;
long long ret;
long long dp[34][34];

void go(){
    for(int w=0; w<=30; w++){
        for(int h=0; h<=30; h++){
            if(w==0) dp[w][h]=1;
            else if(w!=0 && h==0) dp[w][h] = dp[w-1][h+1];
            else dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    go();
    while(true){
        cin>>n;
        if(n == 0) break;
        cout<<dp[n][0]<<"\n";
    }
    
    return 0;
}
