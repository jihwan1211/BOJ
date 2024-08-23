#include <bits/stdc++.h>
using namespace std;

int N, K;
// pos , cnt
queue<pair<int, int>> q;
int visited[100004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    q.push({N, 0});

    while(q.size()){
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[pos] = cnt;
        if(pos == K) {
            cout<<cnt;
            break;
        }
        if(pos*2 <= 100000 && !visited[pos*2]) {
           q.push({pos*2, cnt});
        }
        if(pos-1 >=0 && !visited[pos-1]) q.push({pos-1, cnt+1});
        if(pos+1 <= 100000 && !visited[pos+1]) q.push({pos+1, cnt+1});
       
    }

    return 0;
}