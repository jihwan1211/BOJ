#include <bits/stdc++.h>
using namespace std;

int t, w, ret;
int arr[32][1004];
vector<int> vec;

void go(){ 
    for(int i = 0; i <= w; i++){
        for(int j = 0; j < t; j++){
            int tree_pos = (i % 2) + 1; // 현재 자두의 위치 (i번 움직였다면 어느 나무 아래에 있는가)
            int ja_cnt = (vec[j] == tree_pos) ? 1 : 0; // 현재 초에 떨어지는 자두를 받을 수 있다면 1, 아니면 0

            if(j == 0){
                arr[i][j] = ja_cnt; // 첫 초에는 이전 값이 없으므로 현재 값만 저장
            } else if(i == 0){
                arr[i][j] = arr[i][j-1] + ja_cnt; // 움직이지 않는 경우, 이전 초의 값에 현재 초의 결과를 더함
            } else {
                arr[i][j] = max(arr[i-1][j-1], arr[i][j-1]) + ja_cnt; // 움직이거나, 움직이지 않는 경우 중 최대값 선택 후 현재 초의 결과를 더함
            } 
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;
    vec.resize(t);
    for(int i = 0; i < t; i++){
        cin >> vec[i]; 
    }

    go(); 

    for(int i = 0; i <= w; i++) {
        ret = max(ret, arr[i][t-1]);  
    }

    cout << ret; 
    return 0;
}