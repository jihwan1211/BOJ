#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long go(int timess){
    if(timess == 1) return A%C;
    else{
        if(timess%2){
            int res = go(timess-1);
            return ((A%C)*res%C)%C;
        }else{
            int res = go(timess/2);
            return (res%C*res%C)%C;
        }
        
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>A>>B>>C;
    cout<<go(B);
    return 0;
}