#include <bits/stdc++.h>
using namespace std;

int n,m, temp;
int arr[10004];
vector<int> vec;
vector<int> ret;

void my_print(){
    for(int i=0; i<m; i++) cout<<ret[i]<<" ";
    cout<<"\n";
    return;
}

void go(){
    if(ret.size() == m){
        my_print();
        return;
    }
    for(int i=0; i<vec.size(); i++){
        if(!ret.size()) {
            ret.push_back(vec[i]);
            go();
            ret.pop_back();
        }
        else{
            if(ret[ret.size()-1] <= vec[i]) {
                ret.push_back(vec[i]);
                go();
                ret.pop_back();
            }
        }
    }
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        cin>>temp;
        if(arr[temp]) continue;
        arr[temp] = 1;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    go();

    return 0;
}