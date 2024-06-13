#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr_zero[44];
int arr_one[44];

void fibo(){
    arr_zero[0] = 1;
    arr_zero[1] = 0;
    arr_one[0] = 0;
    arr_one[1] = 1;
    for(int i=2; i<44; i++){
        arr_zero[i] = arr_zero[i-1] + arr_zero[i-2];
        arr_one[i] = arr_one[i-1] + arr_one[i-2];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    fibo();
    for(int i=0; i<t; i++) {
        cin>>n;
        cout<<arr_zero[n]<<" "<<arr_one[n]<<"\n";
    }
    return 0;
}
