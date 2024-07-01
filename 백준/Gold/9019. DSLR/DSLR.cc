#include <bits/stdc++.h>
using namespace std;

int t, a, b, from, to;

int D(int n){
    n = n*2;
    if(n > 9999) n = n%10000;
    return n;
}

int S(int n){
    if(n == 0) return 9999;
    else return n-1;
}

int L(int n) {
    return (n % 1000) * 10 + n / 1000;
}

int R(int n) {
    return (n % 10) * 1000 + n / 10;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>from>>to;
        string visited[10004];
        queue<int> q;
        q.push(from);
        visited[from] = "A";
        while(q.size()){
            int front = q.front();
            q.pop(); 
            if(front == to) {
                for(int i=1; i<visited[front].size(); i++){
                    cout<<visited[front][i];
                }
                cout<<"\n";
                break;
            }

            int temp = 0;
            temp = D(front);
            if(visited[temp] == "") {
                q.push(temp);
                visited[temp] = visited[front] + "D";
            }
            temp = S(front);
            if(visited[temp] == "") {
                q.push(temp);
                visited[temp] = visited[front] + "S";
            }
            temp = L(front);
            if(visited[temp] == "") {
                q.push(temp);
                visited[temp] = visited[front] + "L";
            }
            temp = R(front);
            if(visited[temp] == "") {
                q.push(temp);
                visited[temp] = visited[front] + "R";
            }

        }
    }
    return 0;
}   