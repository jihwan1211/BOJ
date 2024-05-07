#include <bits/stdc++.h>
using namespace std;

int n, m, from, to;
int arr[2004];
int dp[2004][2004];
vector<pair<int, int>> vec;

// void go(){
//     for(int i=0; i<m; i++){
//         from = vec[i].first;
//         to = vec[i].second;
//         int length = to - from;
//         if(length == 0){
//             cout<<1<<"\n";
//             continue;
//         }

//         if(length%2){// 짝수개 검새
//             bool flag=true;
//             for(int j=0; j<=length/2; j++){
//                 if(arr[j+from] == arr[from+length-j]) continue;
//                 else {
//                     flag=false;
//                     break;
//                 }
//             }
//             if(!flag) cout<<0<<"\n";
//             else cout<<1<<"\n";
//         }else{// 홀수개 검사
//             bool flag = true;
//             for(int j=0; j<length/2; j++){
//                 if(arr[j+from] == arr[from+length-j]) continue;
//                 else{
//                     flag=false;
//                     break;
//                 }
//             }
//             if(!flag) cout<<0<<"\n";
//             else cout<<1<<"\n";
//         }
//     }
// }

void go(int from, int to){
    int length = to - from;
    if(length == 0) dp[from][to] =1;
    else if(length == 1){
        if(arr[from] == arr[to]) dp[from][to] = 1;
        else dp[from][to]=0;
        return;
    }else{
        if(arr[from] == arr[to]){
            if(from+1 == to-1) {
                dp[from][to]=1;
                return;
            }
            if(dp[from+1][to-1] == -1) go(from+1, to-1);
            if(dp[from+1][to-1]) dp[from][to] = 1;
            else dp[from][to] = 0;
        }else dp[from][to]=0;
    }
}

void init(){
    for(int i=0; i<2001; i++){
        for(int j=0; j<2001; j++){
            if(i == j) dp[i][j] = 1;
            else continue;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>from>>to;
        vec.push_back({from-1, to-1});
    }
    // init();
    fill(&dp[0][0], &dp[0][0] + 2004*2004, -1);

    for(int i=0; i<m; i++){
        from = vec[i].first;
        to = vec[i].second;
        if(dp[from][to] == -1) go(from, to);

        if(dp[from][to]) cout<<1<<"\n";
        else cout<<0<<"\n";
    }

    return 0;
}