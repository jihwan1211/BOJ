#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    int cnt=0;
    for(int i=0; i<=(1<<6); i++){
        if(i == n){
            for(int j=0; j<7; j++){
                if(i&(1<<j)) cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}