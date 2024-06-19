#include <bits/stdc++.h>
using namespace std;

long long n, temp;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>temp;
        if(!pq.size()){
            if(temp == 0) cout<<0<<"\n";
            else pq.push(temp);
        }
        else if(pq.size()){
            if(temp == 0){
                cout<<pq.top()<<"\n";
                pq.pop();
            }else pq.push(temp);
        }
    }
    return 0;
}