#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string s;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>s;   
    int cur =1, prev = 0, next = 2;
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[prev] == 'I' && s[cur]=='O' && s[next] == 'I'){
            cnt++;
            cur+=2;
            prev+=2;
            next+=2;
        }else{
            if(n > cnt){
                cnt = 0;
            }else{
                ret += cnt - n + 1;
                cnt = 0;
            }
            cur++;
            prev++;
            next++;
        }
        if(next > s.size()) break;
    }
    if(n > cnt){
        cnt = 0;
    }else{
        ret += cnt - n + 1;
    }
    
    cout<<ret;
    return 0;
}
