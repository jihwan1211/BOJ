#include <bits/stdc++.h>
using namespace std;

int n, ret;
int arr[17][17];
// dir:0 가로, 1:세로, 2:대각

void go(int y, int x, int dir){
    if(y<0 || y>=n || x<0 || x>=n) return;
    if(arr[y][x]) return;
    if(dir == 2){
        if(arr[y-1][x] || arr[y][x-1]) return;
    }
    if(y==n-1 && x==n-1) {
        ret++;
        return;
    }
    // 가로
    if(dir == 0){
        // 가로
        go(y, x+1, 0);
        // 대각
        go(y+1, x+1, 2);
    }else if(dir==1){ // 세로
        // 세로
        go(y+1, x, 1);
        // 대각
        go(y+1, x+1, 2);
    }else{ // 대각
        // 가로
        go(y, x+1, 0);
        // 세로
        go(y+1, x, 1);
        // 대각
        go(y+1, x+1, 2);
    }
    
    
    
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    // 가로
    go(0, 1, 0);
    cout<<ret;
    return 0;
}

