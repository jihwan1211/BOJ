#include <bits/stdc++.h>
using namespace std;

int V, E, from, to, edgeNum, cost;
vector<pair<int, pair<int, int>>> vec;
int parent[10004];

int getParent(int x) {
    if(parent[x] == x) return x;
    parent[x] = getParent(parent[x]);
    return parent[x];
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool isSameParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;
    for(int i=0; i<E; i++){
        cin>>from>>to>>cost;
        vec.push_back({cost, {from, to}});
    }
    sort(vec.begin(), vec.end());
    for(int i=1; i<=V; i++) parent[i] = i;

    int pos = 0;
    int ret = 0;
    while(1){
        // 끝
        if(edgeNum == V-1) {
            break;
        }

        int cost = vec[pos].first;
        int posA = vec[pos].second.first;
        int posB = vec[pos].second.second;

        if(edgeNum == 0){
            if(posA < posB) parent[posB] = posA;
            edgeNum++;
            ret += cost;
        }else {
            if(!isSameParent(posA, posB)) {
                unionParent(posA, posB);
                edgeNum++;
                ret += cost;
            }
        }
        pos++;
    }
    cout<<ret;
    return 0;
}
