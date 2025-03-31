#include <bits/stdc++.h>
using namespace std;

int N, answer=-987654321;
int arr[21][21];
int temp[21][21];

void move(int dir, int arr[21][21]){
    if(dir == 0){
        for(int x=0; x<N; x++){
            queue<int> q;
            for(int y=0; y<N; y++){
                if(y == N-1) {
                    if(arr[y][x]) q.push(arr[y][x]);
                    continue;
                }else{
                    if(arr[y][x] > 0){
                        bool isPushed = false;
                        int pos = y+1;
                        while(pos < N){
                            if(arr[pos][x] == 0){
                                pos++;
                            }else{
                                if(arr[pos][x] == arr[y][x]) {
                                    q.push(arr[y][x] + arr[pos][x]);
                                    y=pos;
                                }else{
                                    q.push(arr[y][x]);
                                }
                                isPushed = true;
                                break;
                            }
                        }
                        if(!isPushed) q.push(arr[y][x]);
                        // y = pos;
                    }
                }
            }
            int pos=0;
            for(int i=0; i<N; i++){
                if(q.size()) {
                    arr[pos][x] = q.front();
                    q.pop();
                }else{
                    arr[pos][x] = 0;
                }
                pos++;
            }
        }    
    } else if(dir == 1){
        for(int y=0; y<N; y++){
            queue<int> q;
            for(int x=N-1; x>=0; x--){
                if(x == 0) {
                    if(arr[y][x]) q.push(arr[y][x]);
                } else{
                    if(arr[y][x] > 0){
                        bool isPushed = false;
                        int pos = x-1;
                        while(pos >= 0){
                            if(arr[y][pos] == 0){
                                pos--;
                            }else{
                                if(arr[y][pos] == arr[y][x]) {
                                    q.push(arr[y][x] + arr[y][pos]);
                                    x=pos;
                                }else{
                                    q.push(arr[y][x]);
                                }
                                isPushed = true;
                                break;
                            }
                        }
                        if(!isPushed) q.push(arr[y][x]);
                        // x = pos;
                    }
                }
            }
            int pos = N-1;
            for(int i=0; i<N; i++){
                if(q.size()) {
                    arr[y][pos] = q.front();
                    q.pop();
                }else{
                    arr[y][pos] = 0;
                }
                pos--;
            }
        }        
    } else if(dir == 2){
        for(int x=0; x<N; x++){
            queue<int> q;
            for(int y=N-1; y>=0; y--){
                if(y == 0) {
                    if(arr[y][x]) q.push(arr[y][x]);
                } else {
                    if(arr[y][x] > 0){
                        bool isPushed = false;
                        int pos = y-1;
                        while(pos >= 0){
                            if(arr[pos][x] == 0){
                                pos--;
                            }else{
                                if(arr[pos][x] == arr[y][x]) {
                                    q.push(arr[y][x] + arr[pos][x]);
                                    y=pos;
                                }else{
                                    q.push(arr[y][x]);
                                }
                                isPushed = true;
                                break;
                            }
                        }
                        if(!isPushed) q.push(arr[y][x]);
                        // y = pos;
                    }
                }
            }
            int pos = N-1;
            for(int i=0; i<N; i++){
                if(q.size()) {
                    arr[pos][x] = q.front();
                    q.pop();
                }else{
                    arr[pos][x] = 0;
                }
                pos--;
            }
        }        
    } else {
        for(int y=0; y<N; y++){
            queue<int> q;
            for(int x=0; x<N; x++){
                if(x == N-1) {
                    if(arr[y][x]) q.push(arr[y][x]);
                }else {
                    if(arr[y][x] > 0){
                        bool isPushed = false;
                        int pos = x+1;
                        while(pos < N){
                            if(arr[y][pos] == 0){
                                pos++;
                            }else{
                                if(arr[y][pos] == arr[y][x]) {
                                    q.push(arr[y][x] + arr[y][pos]);
                                    x=pos;
                                }else{
                                    q.push(arr[y][x]);
                                }
                                isPushed = true;
                                break;
                            }
                        }
                        if(!isPushed) q.push(arr[y][x]);
                        // x = pos;
                    }
            
                }
            }
            int pos = 0;
            for(int i=0; i<N; i++){
                if(q.size()) {
                    arr[y][pos] = q.front();
                    q.pop();
                }else{
                    arr[y][pos] = 0;
                }
                pos++;
            }
        }             
    }
}

void dfs(int cnt, int before_move_arr[21][21]){
    if(cnt == 5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                answer = max(answer, before_move_arr[i][j]);
            }
        }
        return;
    }
    for(int dir=0; dir<4; dir++){
        int temp[21][21];
        memcpy(temp, before_move_arr, sizeof(arr));
        move(dir, temp);
        dfs(cnt+1, temp);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
 
    dfs(0, arr);
    
    cout<<answer;
    return 0;
}
