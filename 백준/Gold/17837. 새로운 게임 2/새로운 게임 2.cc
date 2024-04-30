#include <bits/stdc++.h>
using namespace std;

int n, k, ret, a, b, c;
int arr[15][15];
vector<int> vec[15][15];
// 말 번호, {위치, 방향}
map<int, tuple<int, int, int>> mp;
tuple<int, int, int> t;

const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};

int change_dir(int dir){
    if(dir == 1) return 2;
    else if(dir ==2) return 1;
    else if(dir ==3) return 4;
    else return 3;
}

// k는 몇번째 말인지를 뜻하는 것
void move(int k){
    int y, x, dir;
    tie(y, x, dir) = mp[k];
    int idx=0;
    // temp: 말 번호
    vector<int> temp;
    for(int i=0; i<vec[y][x].size(); i++){
        if(vec[y][x][i] == k) {
            idx=i;
        }
    }
    for(int i=idx; i<vec[y][x].size(); i++){
        temp.push_back(vec[y][x][i]);
    }
    int ny = y+dy[dir];
    int nx = x+dx[dir];
    if(ny<0 || ny>=n || nx<0 || nx>=n || arr[ny][nx] == 2) { // 체스판 벗어나 == 파란색과 동일
        dir = change_dir(dir);
        ny = y+dy[dir];
        nx = x+dx[dir];
        if(ny<0 || ny>=n || nx<0 || nx>=n || arr[ny][nx] == 2) {
            mp[k]=make_tuple(y, x, dir);
            return;
        }
        if (arr[ny][nx] == 0) { // move white
            for(int i=0; i<temp.size(); i++){
                vec[ny][nx].push_back(temp[i]);
                vec[y][x].pop_back();
                if(temp[i] != k){
                    int temp_dir;
                    tie(y, x, temp_dir) = mp[temp[i]];
                    mp[temp[i]] = make_tuple(ny, nx, temp_dir);
                } else mp[temp[i]] = make_tuple(ny, nx, dir);
            }
        }
        else { // move red
            vector<int> reverse_temp;
            for(int i=temp.size()-1; i>=0; i--){
                reverse_temp.push_back(temp[i]);
            }
            for(int i=0; i<reverse_temp.size(); i++){
                vec[ny][nx].push_back(reverse_temp[i]);
                vec[y][x].pop_back();
                if(reverse_temp[i] != k){
                    int temp_dir;
                    tie(y, x, temp_dir) = mp[reverse_temp[i]];
                    mp[reverse_temp[i]] = make_tuple(ny, nx, temp_dir);
                }else mp[reverse_temp[i]]= make_tuple(ny, nx, dir);
            }
        }
        if(vec[ny][nx].size() >= 4) {
                cout<<ret+1;
                exit(0);
        }
    }
    else if(arr[ny][nx] == 0){// 흰색
        for(int i=0; i<temp.size(); i++){
            vec[ny][nx].push_back(temp[i]);
            vec[y][x].pop_back();
            tie(y, x, dir) = mp[temp[i]];
            mp[temp[i]]=make_tuple(ny, nx, dir);
            
        }
    }else if(arr[ny][nx] == 1){ // 빨간색
        vector<int> reverse_temp;
        for(int i=temp.size()-1; i>=0; i--){
            reverse_temp.push_back(temp[i]);
        }
        for(int i=0; i<reverse_temp.size(); i++){
            vec[ny][nx].push_back(reverse_temp[i]);
            vec[y][x].pop_back();
            tie(y, x, dir) = mp[reverse_temp[i]];
            mp[reverse_temp[i]]= make_tuple(ny, nx, dir);
        }
    }
    if(vec[ny][nx].size() >= 4) {
            cout<<ret+1;
            exit(0);
    }
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j].size()<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------\n";
}

void go(){
    int cnt=0;
    while(1){
        for(int i=1; i<=k; i++){
            //tie(y, x, dir) = mp[i];
            move(i);
        }
        // print();
        // cnt++;
        ret++;
        if(ret > 1000) {
            cout<<-1;
            exit(0);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=k; i++){
        cin>>a>>b>>c;
        a--;
        b--;
        t = make_tuple(a, b, c);
        vec[a][b].push_back(i);
        mp.insert({i, t});
    }

    go();
    return 0;
}
