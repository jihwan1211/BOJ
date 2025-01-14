#include <bits/stdc++.h>
using namespace std;
# define INF 1e9
int N, S, from, to=1, sum, len = INF, temp;
int psum[100004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>S;
    psum[0] = 0;
    for(int i=1; i<=N; i++){
        cin>>temp;
        if(i == 1) psum[i] = temp;
        else psum[i] = psum[i-1] + temp;
    }

    // cout<<"\npsum : \n";
    // for(int i=0; i<=N; i++) cout<<psum[i]<<" ";
    // cout<<"\n";

    while(from < to){
        if(from == to) break;
        if(to > N) break;
        else sum = psum[to] - psum[from];
        // cout<<from<<" "<<to<<" "<<sum<<"\n";
        if(sum >= S){
            len = min(len, to-from);
            from++;
            if(len == 1) {
                cout<<len;
                return 0;
            }
        }else{
            to++;
        }
    }

    if(len != INF) cout<<len;
    else cout<<0;
    return 0;
}