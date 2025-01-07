#include <bits/stdc++.h>
using namespace std;

long long n, x, y;
vector<pair<long long, long long>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        vec.push_back({x, y});
    }
    
    long long calc = 0.0;
    pair<long long, long long> pos1, pos2;
    for(int i=0; i<n; i++){
        pos1 = vec[i];
        if(i == n-1) pos2 = vec[0];
        else pos2 = vec[i+1];
        long long pos_1_x = pos1.first;
        long long pos_1_y = pos1.second;
        
        long long pos_2_x = pos2.first;
        long long pos_2_y = pos2.second;

        calc += pos_1_x*pos_2_y - pos_1_y * pos_2_x;
    }
    // cout<<(round(abs(calc)*100)/100)*0.5;
    // 결과를 소수점 두 자리까지 출력
    cout << fixed << setprecision(1) << (round(abs(calc) * 100) / 100.0) * 0.5;
    
    return 0;
}