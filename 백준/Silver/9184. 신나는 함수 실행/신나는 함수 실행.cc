#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int dp[104][104][104];

int w(int a, int b, int c){
    int &ret = dp[a][b][c];
    if(ret != 987654321) return ret;
    if(a<=50 || b<=50 || c<=50) {
        ret= 1;
        return 1;
    }else if(a > 70 || b > 70 || c > 70) {
        ret = w(70, 70, 70);
        return ret;
    }else if(a<b && b<c) {
        ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return ret;
    }

    ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0][0], &dp[0][0][0] + 104*104*104, 987654321);
    while(1){
        cin>>a>>b>>c;
        if(a == -1 && b== -1 && c== -1) break;
        dp[a+50][b+50][c+50] = w(a+50, b+50, c+50);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[a+50][b+50][c+50]<<"\n";
    }
    return 0;
}