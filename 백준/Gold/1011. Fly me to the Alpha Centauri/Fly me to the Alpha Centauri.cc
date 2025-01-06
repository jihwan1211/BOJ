#include <bits/stdc++.h>
using namespace std;

/**
* 매모리 초과 코드
https://www.acmicpc.net/problem/1011
 */
int x, y, T;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    for(int i=0; i<T; i++){
        cin>>x>>y;        
        int l = x;
        int r = y;
        int cnt = 0;
        int prev_step = 0;
        bool flag = false;

        while(l < r){
            if((r-l) == prev_step + 1 || (r-l) <= prev_step){
                cout<<cnt*2 + 1<<"\n";
                flag = true;
                break;
            }
            int next_step = prev_step + 1;
            l+=next_step;
            r-=next_step;
            prev_step++;
            cnt++;
        } 
        if(!flag) cout<<cnt*2<<"\n";
    }
    return 0;
}