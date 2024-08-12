#include <bits/stdc++.h>
using namespace std;

int N, answer;
int row[17];

bool check(int row_num){
    for(int i=0; i<row_num; i++){
        if(row[row_num] == row[i] || (row_num - i) == abs(row[i] - row[row_num])) return false;
    }
    return true;
}

void go(int row_num){
    if(row_num == N) {
        answer++;
        return;
    }
    // 0행부터 N-1행 중 어디에 들어갈지
    for(int i=0; i<N; i++){
        // row_num 행 i열에 일단 놔본다
        row[row_num] = i;
        // 둘 수 있는지 확인
        if(check(row_num)) go(row_num+1);
        row[row_num] = 0;
        
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    go(0);
    cout<<answer;

    return 0;
}