#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
  
    for(int i=0; i<n; i++){
        pq.push(vec[i].second);
        if(pq.size() > vec[i].first) pq.pop();
    }
  
    int size=pq.size();
    for(int i=0; i<size; i++){
        ret+=pq.top();
        pq.pop();
    }
    cout<<ret;
    return 0;
}