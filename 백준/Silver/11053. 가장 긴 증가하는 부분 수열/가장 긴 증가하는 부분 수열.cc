#include <bits/stdc++.h>
using namespace std;

int arr[1004];
int cnt[1004];
int n, ret;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    
    
    for(int i=0; i<n; i++){
        int maxVal = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && maxVal <= cnt[j]) maxVal = cnt[j];
        }
        cnt[i] = maxVal+1;
    }
    for(int i=0; i<n; i++){
        // cout<<cnt[i]<<" ";
        ret=max(ret, cnt[i]);
    }
    cout<<ret;
    
    return 0;
}