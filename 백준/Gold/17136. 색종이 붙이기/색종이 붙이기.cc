#include <bits/stdc++.h>
using namespace std;

int arr[12][12];
int paper[6] = {0, 5, 5, 5, 5, 5};
int ret= 987654321;

bool check(int y, int x, int size){
    if(y+size>10 || x+size>10) return false;

    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(!arr[i][j]) return false;
        }
    }
    return true;
}

void paste_paper(int y, int x, int size){
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            arr[i][j] = 0;
        }
    }
}

void erase_paper(int y, int x, int size){
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            arr[i][j] = 1;
        }
    }
}

void go(int y, int x){
    if(x==10){
        go(y+1, 0);
        return;
    }
    if(y==10){
        int temp = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(arr[i][j]) {
                    temp=987654321;
                     ret = min(ret,temp);
                     return;
                }
            }
        }

        for(int i=0; i<6; i++) temp+=paper[i];
        temp = 25-temp;
        ret = min(ret,temp);
        return;
    }
    
    if(arr[y][x] == 0) {
        go(y, x+1);
        return;
    };

    for(int k=5; k>0; k--){
        if(paper[k] && check(y, x, k)){
            paste_paper(y, x, k);
            paper[k]--;
            go(y, x+k);
            paper[k]++;
            erase_paper(y, x, k);
        }else continue;
   } 
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>arr[i][j];
        }
    }
    
    go(0, 0);

    if(ret == 987654321) cout<<-1;
    else cout<<ret;
    
    return 0;
}