#include<bits/stdc++.h>
using namespace std;

int n, l, ret;
int arr[101][101];
int cnt[101];

void go(int row, int col){
    // for(int i=0; i<row; i++){
    for(int i=0; i<n; i++){
        // 올라갈때
        if(i+1 < n && arr[row][i] == arr[row][i+1]-1){
            if(cnt[i]) return;
            cnt[i] =1;
            int prev = arr[row][i];
            for(int k=1; k<l; k++){
                if(i-k < 0 || cnt[i-k]) {
                    return;
                }
                if(prev == arr[row][i-k]){
                    cnt[i-k]=1;
                }else{
                    return;
                }
                prev=arr[row][i-k];
            }
        // 내려갈때
        }else if(i+1 < n && arr[row][i]== arr[row][i+1] + 1){
            if(l==1){
                cnt[i+1]=1;
                continue;
            }
            else{
                int next=arr[row][i+1];
                for(int k=1; k<l; k++){
                    if(i+1+k>=n){
                        return;
                    }
                    if(arr[row][i+1+k] == next){
                        cnt[i+1+k]=1;
                    }else{
                        return;
                    }
                }
                i+=l-1;
            }
        }else if(i+1<n && abs(arr[row][i] - arr[row][i+1]) > 1){
            return;
        }else {
            continue;
        }
    }
 
    ret++;
    // cout<<row<<"\n";
}

void go2(int row, int col){
    // for(int i=0; i<row; i++){
    for(int i=0; i<n; i++){
        // 올라갈때
        if(i+1 < n && arr[i][row] == arr[i+1][row]-1){
            if(cnt[i]) return;
            cnt[i] =1;
            int prev = arr[i][row];
            for(int k=1; k<l; k++){
                if(i-k < 0 || cnt[i-k]) {
                    return;
                }
                if(prev == arr[i-k][row]){
                    cnt[i-k]=1;
                }else{
                    return;
                }
                prev=arr[i-k][row];
            }
        // 내려갈때
        }else if(i+1 < n && arr[i][row]== arr[i+1][row] + 1){
            if(l==1){
                cnt[i+1]=1;
                continue;
            }
            else{
                int next=arr[i+1][row];
                for(int k=1; k<l; k++){
                    if(i+1+k>=n){
                        return;
                    }
                    if(arr[i+1+k][row] == next){
                        cnt[i+1+k]=1;
                    }else{
                        return;
                    }
                }
                i+=l-1;
            }
        }else if(i+1<n && abs(arr[i][row] - arr[i+1][row]) > 1){
            return;
        }else {
            continue;
        }
    }
 
    ret++;
    // cout<<row<<"\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        memset(cnt, 0, sizeof(cnt));
        go(i, 0);
    }
    
     for(int i=0; i<n; i++){
        memset(cnt, 0, sizeof(cnt));
        go2(i, 0);
    }
    cout<<ret;
    return 0;
}