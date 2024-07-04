#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
int n, x;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>x;
        if(x == 0){ 
            if(!pq.size()) cout<<0<<"\n";
            else {
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }else{
            pq.push({abs(x), x});
        }
    }
    return 0;
}
