#include <bits/stdc++.h>
using namespace std;

int n, white, blue;
int arr[130][130];

void go(int size, int y, int x){
    if(size == 1){
        if(arr[y][x] == 0) white++;
        else blue++;
        return;
    }
    bool isWhite = false;
    bool isBlue = false;
    
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(arr[i][j] == 0) isWhite = true;
            if(arr[i][j] == 1) isBlue = true;
            if(isWhite && isBlue) {
                go(size/2, y, x);
                go(size/2, y, x+size/2);
                go(size/2, y+size/2, x);
                go(size/2, y+size/2, x+size/2);
                return;
            }
        }
    }
    if(isWhite && !isBlue) white++;
    else if(!isWhite && isBlue) blue++;
    return;
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

    go(n, 0, 0);
    cout<<white<<"\n";
    cout<<blue;
    return 0;   
}