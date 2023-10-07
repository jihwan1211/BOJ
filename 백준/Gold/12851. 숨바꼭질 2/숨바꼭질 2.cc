#include<bits/stdc++.h>
using namespace std;

int n, k, ret=987654321;
int arr[100000];
int visited[100004];


void go(int pos, int cnt){
    queue<pair<int, int>> q;
    q.push({pos, cnt});
    while(q.size()){
        tie(pos, cnt) = q.front();
        q.pop();
        visited[pos]=1;
        if(pos<0 || pos>100000) continue;
        if(cnt > ret) continue;
        if(pos == k){
            ret = min(ret, cnt);
            arr[ret]++;
            continue;
        }
        if(pos+1 <= 100000 && !visited[pos+1]) q.push({pos+1, cnt+1});
        if(pos-1 >=0 && !visited[pos-1]) q.push({pos-1, cnt+1});
        if(pos*2 <=100000 && !visited[pos*2]) q.push({pos*2, cnt+1});
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>k;

    go(n, 0);
    cout<<ret<<"\n"<<arr[ret];
    return 0;
}