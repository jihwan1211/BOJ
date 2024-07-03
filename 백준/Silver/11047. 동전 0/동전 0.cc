#include <bits/stdc++.h>
using namespace std;

int n, k, arr[14], ret;

void go(int money){
    if(money == 0) return;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > money) continue;
        else if(arr[i] == money) {
            ret++;
            money = 0;
            return;
        }else{
            ret+=money/arr[i];
            go(money % arr[i]);
            
            break;
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    go(k);
    cout<<ret;
    return 0;
}