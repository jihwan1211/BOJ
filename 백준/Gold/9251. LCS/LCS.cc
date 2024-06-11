#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int dp[1004][1004];

void go(){
    for(int i=0; i<str1.length(); i++){
        for(int j=0; j<str2.length(); j++){
            if(i==0 && j==0){
                if(str1[i] == str2[j]) dp[i][j] = 1;
                else dp[i][j] = 0;
                continue;
            }
            if(i==0 || j==0) {
                if(i==0) {
                    if(str1[i] == str2[j]) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j-1];
                }
                else if (j==0){
                    if(str1[i] == str2[j]) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j];
                }
                continue;
            }
            if(dp[i][j-1] >= i+1) {
                dp[i][j] = dp[i][j-1]; 
                continue;
            }
            if(str1[i] == str2[j]) dp[i][j] =dp[i-1][j-1] +1 ;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
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