#include <bits/stdc++.h>
using namespace std;

int n;
int arr[304];
int dp[304][304];

int go(int curIdx, int prevIdx, int csNum){
    if(curIdx == n) return arr[curIdx];
    int &ret = dp[curIdx][prevIdx];
    if(ret) return ret;

    if(curIdx == n-1) {
        if(csNum == 2) return -987654321;
        else ret= go(curIdx+1, curIdx, csNum+1) + arr[curIdx];
    }else{
        if(csNum == 2) ret = go(curIdx+2, curIdx, 1) + arr[curIdx];
        else {
            ret = max(go(curIdx + 1, curIdx, csNum+1), go(curIdx+2, curIdx, 1)) + arr[curIdx];
        }
    }
  
    return ret;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    arr[0]=0;
    for(int i=1; i<=n; i++) cin>>arr[i];
    dp[0][0] = 0;
    if(n==1) cout<<arr[1];
    else cout<< max(go(1, 0, 1),go(2, 0, 1));
    return 0;
}