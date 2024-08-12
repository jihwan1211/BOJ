#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int dp[1004][1004];

void go(){
    
    for(int i=0; i<str2.length(); i++){
        if(str1[0] == str2[i]) dp[0][i] = 1;
        if(i>0 && dp[0][i-1]) dp[0][i] = 1;
    }

    for(int i=1; i<str1.length(); i++){
        for(int j=0; j<str2.length(); j++){
            if(j==0){
                if(str1[i] == str2[j]) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j];
            }else{
                if(str1[i] == str2[j]) dp[i][j] =dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str1>>str2;

    go();
    cout<<dp[str1.length()-1][str2.length()-1];
    return 0;
}