#include <bits/stdc++.h>
using namespace std;

int t, w, ret;
int arr[32][1004];
vector<int> vec;

void go(){
    //arr[w][t] t초이고, w번 움직였을때 받는 자두의 최대
    for(int i=0; i<=w; i++){
        for(int j=0; j<t; j++){
            int temp_pos=0;
            int ja_cnt=0;
            if(i%2 == 0){
                temp_pos = 1;
                if(vec[j] == temp_pos) ja_cnt=1;
            }else{
                temp_pos = 2;
                if(vec[j] == temp_pos) ja_cnt=1;
            }

            if(i == 0){
                if(j != 0) arr[i][j] = arr[i][j-1]+ja_cnt;
                else arr[i][j] = ja_cnt;
            }else{
                if(j != 0) arr[i][j] = max(arr[i-1][j-1], arr[i][j-1]) + ja_cnt;
                // else arr[i][j] = arr[i-1][j] + ja_cnt; // 여기가 틀린 거 같네
                else arr[i][j] = ja_cnt; // 여기가 틀린 거 같네
            } 
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t>>w;

    for(int i=0; i<t; i++){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    go();
    for(int i=0; i<=w; i++) {
        ret=max(ret, arr[i][t-1]);
    }
    
    cout<<ret;
    return 0;
}