#include <bits/stdc++.h>
using namespace std;

int n, k, l, bodylong=1, t;
int a, b;
int arr[102][102];
int visited[102][102];
vector<pair<int, char>> vec;
queue<pair<int, int>> q;
pair<int, int> head;
bool flag = true;


int dy=0, dx=1;

void rotate(char direction){
    if(dy == 0 && dx == 1){
        if(direction == 'L'){
            dy = -1;
            dx = 0;
        }else{
            dy = 1;
            dx = 0;
        }
    }else if (dy==-1 && dx == 0){
        if(direction == 'L'){
            dy = 0;
            dx = -1;
        }else{
            dy = 0;
            dx = 1;
        }
    }else if(dy == 1 && dx == 0){
        if(direction == 'L'){
            dy = 0;
            dx = 1;
        }else{
            dy = 0;
            dx = -1;
        }
    }else if(dy==0 && dx==-1){
        if(direction == 'L'){
            dy = 1;
            dx = 0;
        }else{
            dy = -1;
            dx = 0;
        }
    }
}

void moveHead(){
    head.first += dy;
    head.second += dx;
    if(visited[head.first][head.second] || (head.first < 0 || head.first >=n || head.second < 0 || head.second >= n)){
        // game over
        flag=false;
        return;
    }
    // cout<<t<<":"<<head.first<<", "<<head.second<<"\n";
    q.push({head.first, head.second});
    visited[head.first][head.second]=1;
    if(arr[head.first][head.second]) {
        bodylong++;
        arr[head.first][head.second] = 0;
    }
    if(bodylong != q.size()){
        tie(a, b) = q.front();
        // cout<<a<<", "<<b<<"\n";
        q.pop();
        visited[a][b]=0;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>k;
    if(k){
        for(int i=0; i<k; i++){
            cin>>a>>b;
            arr[a-1][b-1]=1;
        }
   }
   cin>>l;
   for(int i=0; i<l; i++){
        int t;
        char c;
        cin>>t>>c;
        vec.push_back({t, c});
   }
   q.push({0, 0});
   visited[0][0]=1;
   int rotate_when=0;
    while(1){
        t++;
        moveHead();
        if(!flag) break;
        if(t==vec[rotate_when].first){
            rotate(vec[rotate_when].second);
            if(rotate_when < l-1) rotate_when++;
        }
    }
    cout<<t;
    return 0;
}