#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
long long mod_num = 1000000007, k;

long long go(long long n){
    if(mp.find(n) != mp.end()) return mp[n];
    if(n==0) return 0;
    if(n==1) return 1;

    long long res;
    if(n%2 == 0) {
        res = (go(n/2)*(go(n/2+1) + go(n/2-1)))%mod_num;
    }
    if(n%2) {
      res = (go((n+1)/2)*go((n+1)/2) + go((n-1)/2)*go((n-1)/2)) % mod_num;

    }

    // res => 계산된 정답.
    mp.insert({n, res});
    return mp[n];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k;

    mp.insert({0, 0});
    mp.insert({1, 1});
    mp.insert({2, 1});
    
    cout<<go(k);
    return 0;
}