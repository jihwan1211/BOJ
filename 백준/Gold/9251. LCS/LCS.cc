#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int dp[1002][1002];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str1>>str2;
    for(int i=0; i<str1.length(); i++){
        for(int j=0; j<str2.length(); j++){
            if(j==0){
                if(str1[i] == str2[j]) dp[i][j] = 1;
                else{
                    if(i!=0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = 0;
                }
            }else{
                if(str1[i] == str2[j]){
                    if(i==0) dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                }else{
                    if(i==0) dp[i][j] = dp[i][j-1];
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
    }


    cout<<dp[str1.length()-1][str2.length()-1];

    return 0;
}