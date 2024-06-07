#include <bits/stdc++.h>
using namespace std;

int n, arr[1004], cnt[1004], cnt2[1004], ret=-1, pos=-1;

void go(){
    for(int i=0; i<n; i++){
        int num = arr[i];
        int max_cnt = 0;
        for(int j=0; j<i; j++){
            if(num > arr[j]) max_cnt = max(max_cnt, cnt[j]);
        }
        cnt[i] = max_cnt+1;
    }

    for(int i=n-1; i>=0; i--){
        int num = arr[i];
        int max_cnt = 0;
        for(int j=n-1; j>i; j--){
            if(num > arr[j]) max_cnt = max(max_cnt, cnt2[j]);
        }
        cnt2[i] = max_cnt+1;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];

    go();
    for(int i=0; i<n; i++){
        ret = max(ret, cnt[i] + cnt2[i]-1);
    }
    cout<<ret;
    return 0;
}