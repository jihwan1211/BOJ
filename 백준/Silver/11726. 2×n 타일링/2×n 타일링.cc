#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3; i<1004; i++){
        arr[i] = arr[i-1]%10007 + arr[i-2]%10007;
    }

    cout<<arr[n]%10007;
    return 0;
}

