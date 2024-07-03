#include <bits/stdc++.h>
using namespace std;

int n;
long long temp;
priority_queue<long long, vector<long long>, less<long long>> pq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>temp;
        if(temp > 0){
            pq.push(temp);
        }else if(temp == 0){
            if(!pq.size()) cout<<0<<"\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
    }
    return 0;
}
