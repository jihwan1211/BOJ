#include <bits/stdc++.h>
using namespace std;

long long n, s, m, ret;
long long mod = 1000000007;

long long go(long long num, long long cnt){
    if(cnt == 1) return num%mod;

    long long prev = go(num, cnt/2);

    long long next = (prev * prev)%mod;

    if(cnt%2){
        next =  next * (num % mod);
        next %= mod;
    }
    return next;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m;

    for(int i=0; i<m; i++){
        cin>>n>>s;
        s%=mod;
        n%=mod;
        long long temp = go(n, 1000000005);
        ret += (s*temp) % mod;
    }
    cout<<ret%mod;
    return 0;
}