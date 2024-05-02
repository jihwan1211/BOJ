#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, ret=987654321;
// int arr[100004][100004];
map<pair<int, int>, int> m;

// void go(int cur_a, int cur_b, int cnt){
//     if(cur_a == c && cur_b == d){
//         ret=min(ret, cnt);
//         return;
//     }
//     if(cur_a == 0 && cur_b == 0){
//         go(a, 0, cnt+1);
//         go(0, b, cnt+1);
//     }else if(cur_a == a && cur_b==b){
//         go(0, b, cnt+1);
//         go(a, 0, cnt+1);
//     }else{
//         // a에 모든 거를 채우거나 b에 물을 가득 채우는 경우의 수
//         go(a, cur_b, cnt++);
//         go(cur_a, b, cnt++);
//         // 버리는 경우의 수
//         go(0, cur_b, cnt++);
//         go(cur_a, 0, cnt++);
//         // 옮기는 경우의 수
//         // a -> b
//         if(b-cur_b >= cur_a) go(0, cur_b+cur_a, cnt++);
//         else go(cur_a-(b-cur-b), b, cnt++);
//         // b->a
//         if(a-cur_a >= b) go(cur_a+cur_b, 0, cnt++);
//         else go(a, cur_b-(a-cur_a), cnt++);
//     }
// }

// void go(int cur_a, int cur_b, int cnt){
//     if(arr[cur_a][cur_b]) {
//         return;
//         // cout<<-1;
//         // exit(0);
//     }
//     if(cur_a == c && cur_b == d){
//         ret=min(ret, cnt);
//         return;
//     }

//     arr[cur_a][cur_b] = cnt;

//         // a에 모든 거를 채우거나 b에 물을 가득 채우는 경우
//     go(a, cur_b, cnt++);
//     go(cur_a, b, cnt++);
//         // 버리는 경우
//     go(0, cur_b, cnt++);
//     go(cur_a, 0, cnt++);

//         // 옮기는 경우
//         // a -> b
//     if(b-cur_b >= cur_a) go(0, cur_b+cur_a, cnt++);
//     else go(cur_a-(b-cur-b), b, cnt++);
//         // b->a
//     if(a-cur_a >= b) go(cur_a+cur_b, 0, cnt++);
//     else go(a, cur_b-(a-cur_a), cnt++);
    
//     arr[cur_a][cur-b] = 0;
// }

void bfs(int y, int x, int cnt){
    queue<pair<int, int>> q;
    q.push({y, x});
    m[{y, x}] = 1;
    // m.insert({y, x}, 1);
    while(q.size()){
        if(m[{c, d}]) {
            // cout<<"finish";
            return;
        }
        int cur_a, cur_b;
        tie(cur_a, cur_b) = q.front();
        q.pop();
        // cout<<cur_a<<" "<<cur_b<<"\n";

        if(!m[{0, cur_b}]){
            q.push({0, cur_b});
            // arr[0][cur_b] = arr[cur_a][cur_b] + 1;
            m[{0, cur_b}] = m[{cur_a, cur_b}] +1;
        }
        if(!m[{cur_a, 0}]){
            q.push({cur_a, 0});
            // arr[cur_a][0] = arr[cur_a][cur_b] + 1;
            m[{cur_a, 0}] = m[{cur_a, cur_b}] +1;
        }

        if(!m[{a, cur_b}]) {
            q.push({a, cur_b});
            // arr[a][cur_b] = arr[cur_a][cur_b] + 1;
            m[{a, cur_b}] = m[{cur_a, cur_b}] + 1;
        }
        if(!m[{cur_a, b}]){
            q.push({cur_a, b});
            // arr[cur_a][b] = arr[cur_a][cur_b] + 1;
            m[{cur_a, b}] = m[{cur_a, cur_b}] + 1;
        }

        if(b-cur_b >= cur_a){
            if(!m[{0, cur_b+cur_a}]){
                q.push({0, cur_a+cur_b});
                // arr[0][cur_a+cur_b] = arr[cur_a][cur_b] + 1;
                m[{0, cur_a+cur_b}] = m[{cur_a, cur_b}] + 1;
            }
        }else{
            if(!m[{cur_a-(b-cur_b), b}]){
                q.push({cur_a-(b-cur_b), b});
                // arr[cur_a-(b-cur_b)][b] = arr[cur_a][cur_b] + 1;
                m[{cur_a-(b-cur_b), b}] = m[{cur_a, cur_b}]+ 1;
            }
        }

        if(a-cur_a >= cur_b){
            if(!m[{cur_a+cur_b, 0}]){
                q.push({cur_a+cur_b, 0});
                // arr[cur_a+cur_b][0] = arr[cur_a][cur_b] + 1;
                  m[{cur_a+cur_b, 0}] = m[{cur_a, cur_b}] + 1;
            }
        }
        else{
            if(!m[{a, cur_b-(a-cur_a)}]){
                q.push({a, cur_b-(a-cur_a)});
                m[{a,cur_b-(a-cur_a)}] = m[{cur_a,cur_b}] + 1;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b>>c>>d;

    bfs(0, 0, 1);
    if(m[{c, d}]) cout<<m[{c, d}]-1;
    else cout<<-1;

    return 0;
}