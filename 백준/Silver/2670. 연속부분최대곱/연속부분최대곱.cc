#include <bits/stdc++.h>
using namespace std;

int n;
int start;
double arr[10004];
double psum, ret;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    start = 0;
    psum=arr[0];
    for(int i=1; i<n; i++){
        psum*=arr[i];
        if(psum < arr[i]) {
            start=i;
            psum=arr[i];
        }
     
        ret=max(ret, psum);
    }

    // cout<<ret;
    printf("%.3lf", ret + 0.00001); 
    return 0;
}