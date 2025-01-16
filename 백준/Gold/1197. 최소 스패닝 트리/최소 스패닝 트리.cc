#include <bits/stdc++.h>
using namespace std;

int V, E, from, to, cost, ret;
vector<pair<int, pair<int, int>>> vec;
int parent[10004];

int findParent(int pos){
    if(parent[pos] == pos) return pos;
    parent[pos] = findParent(parent[pos]);
    return parent[pos];
}

void mergeParent(int pos1, int pos2){
    pos1 = findParent(pos1);
    pos2 = findParent(pos2);
    if(pos1 < pos2) parent[pos2] = pos1;
    else parent[pos1] = pos2;
}

bool isSameParent(int pos1, int pos2){
    pos1 = findParent(pos1);
    pos2 = findParent(pos2);
    if(pos1 == pos2) return true;
    else return false;
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
    int edgeNum = 0;
    while(true){
        if(edgeNum == V-1) break;
        int here_cost = vec[pos].first;
        int pos1 = vec[pos].second.first;
        int pos2 = vec[pos].second.second;

        if(!isSameParent(pos1, pos2)) {
             mergeParent(pos1, pos2);
            edgeNum++;
            ret+=here_cost;
        }  
        
        pos++;
    }
    cout<<ret;
    return 0;
}