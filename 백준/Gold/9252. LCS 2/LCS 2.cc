#include <bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/9252
int arr[1024][1024];
string str1, str2;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str1>>str2;

    for(int i=0; i<str1.length(); i++){
        for(int j=0; j<str2.length(); j++){
            if(i==0){
                if(j==0) {
                    if(str1[i] == str2[j]) arr[i][j] = 1;
                    else arr[i][j] = 0;
                }else{
                    if(str1[i] == str2[j]) arr[i][j] = 1;
                    else arr[i][j] = arr[i][j-1];
                }
            }else{
                if(j==0) {
                    if(str1[i] == str2[j]) arr[i][j] = 1;
                    else arr[i][j] = arr[i-1][j];
                }else{
                    if(str1[i] == str2[j]) arr[i][j] = arr[i-1][j-1] + 1;
                    else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
    }

    // for(int i=0; i<str1.length(); i++){
    //     for(int j=0; j<str2.length(); j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    queue<char> q;
    int row = str1.length() - 1;
    int col = str2.length() - 1;
    while(true){
        // row,  col이 범위 내에 있는지...
        if(row < 0 || col < 0) break;
        // 단어가 같은지 확인
        if(str1[row] == str2[col]){
            q.push(str2[col]);
            row--;
            col--;
            continue;
        }else{
            // 단어가 달라
            if(row == 0 && col == 0) break;
            else if(row == 0 && col != 0){
                // row가 0일때는 col만 줄이면서 확인
                col--;
            }else if(row != 0 && col == 0){
                // col이 0일때는 row만 줄이면서 확인
                row--;
            }else{        
                if(arr[row-1][col] > arr[row][col-1]){
                // 위가 더 커
                    row--;
                    continue;
                }else if(arr[row-1][col] < arr[row][col-1]){
                // 옆이 더 커
                    col--;
                    continue;
                }else{
                    // 같아
                    row--;
                    continue;
                }
            }
        }
    }


    string answer = "";
    int answer_size = q.size();
    while(q.size()){
        answer += q.front();
        q.pop();
    }
    cout<<answer_size<<"\n";
    if(answer_size) {
        reverse(answer.begin(), answer.end());
        cout<<answer;
    }
    
    return 0;
}