#include <bits/stdc++.h>
using namespace std;

long long arr[92], n;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    arr[1] = 1;
    arr[2] = 1;
    for(int i=3; i<=90; i++) arr[i] = arr[i-1] + arr[i-2];

    cout<<arr[n];

    return 0;
}