#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int visited[10004];
vector<int> vec;
vector<int> ret;

void my_print(){
    for(int i=0; i<ret.size(); i++) cout<<ret[i]<<" ";
    cout<<"\n";
    return ;
}

void go(){
    if(ret.size() == m) {
        my_print();
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[vec[i]]){
            ret.push_back(vec[i]);
            visited[vec[i]] = 1;
            go();
            ret.pop_back();
            visited[vec[i]] = 0;
        }
    }
    
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    go();
    
    return 0;
}