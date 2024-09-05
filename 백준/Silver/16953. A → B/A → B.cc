#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

long long a, b, ret = -1;
map<int, int> mp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b;

    // 숫자, 횟수
    queue<pair<int, int>> q;
    q.push({a, 1});
    mp.insert({a, 1});
    while(q.size()){
        long long num = q.front().first;
        long long cnt = q.front().second;
        q.pop();

        if(num == b){
            ret = cnt;
            break;
        }
        
        if(num*2 <= INF && num*2 > 0){
            if(mp.find(num*2) == mp.end()) {
                q.push({num*2, cnt+1});
                mp.insert({num*2, cnt+1});
            }
        }
        if(num*10 + 1 <= INF && num*10 +1 > 0){
            if(mp.find(num*10 + 1) == mp.end()){
                q.push({num*10 + 1, cnt+1});
                mp.insert({num*10+1, cnt+1});
            }
            
        }
    }
    cout<<ret;
    return 0;
}