#include <bits/stdc++.h>
using namespace std;

// 이분탐색?
long long lo, hi;
long long temp_ans;
long long n, m;
long long arr[1000004];

long long check(long long length){
    long long sum=0;
    long long remain = 0;
    for(int i=0; i<n; i++){  
        remain = arr[i] - length;
        if(remain > 0) sum+=remain;
    }
    if(sum == m) return 1;
    else if(sum < m) return 0;
    else return 2;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    hi = 1000000000;
    bool fine_end = false;
    while(lo<=hi){
        long long mid = (lo+hi)/2;
        long long check_result = check(mid);
        if(check_result == 1){
            fine_end = true;
            cout<<mid;
            break;
        }else if(check_result == 2){
            lo = mid+1;
            temp_ans = max(temp_ans, mid);
        } else {
            hi = mid-1;
        }
        // cout<<mid<<"\n";
    }
    if(!fine_end) cout<<temp_ans;
    return 0;
}
