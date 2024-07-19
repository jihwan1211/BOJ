#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int x, y;
int visited[40004];

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int go(){
    if(x == y) return x;
    int diff = M-N;
    int cal_y = x;
    int ret = x;
    if(cal_y > N) cal_y = cal_y % N;
    if(cal_y < 1) cal_y = N + cal_y;
    if(cal_y == y) return ret;
    visited[cal_y] = 1;
    while(ret <= lcm(M, N)){
        cal_y += diff;
        if(cal_y > N) cal_y = cal_y % N;
        if(cal_y < 1) cal_y = N + cal_y;
        ret += M;
        if(cal_y == y) return ret;
        if(visited[cal_y]) return -1;
        visited[cal_y] = 1;
        // cout<<"ret : "<<ret<<"\n";
        // cout<<cal_y<<"\n";
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout<<lcm(37777, 40000);
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>M>>N>>x>>y;
        cout<<go()<<"\n";
        fill(&visited[0], &visited[0] + 40004, 0);
    }

    return 0;
}