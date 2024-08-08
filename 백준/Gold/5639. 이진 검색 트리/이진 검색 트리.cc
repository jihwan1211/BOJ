#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int arr[1000004][2];
int root;

void go(int value, int node){
    if(node > value){
        if(arr[node][0] == -1) {
            arr[node][0] = value;
            return;
        }else{
            go(value, arr[node][0]);
        }
    }else{
        if(arr[node][1] == -1){
            arr[node][1] = value;
            return;
        }else {
            go(value, arr[node][1]);
        }
    }
    
    
}

void postOrder(int value){
    if(arr[value][0] != -1){
        postOrder(arr[value][0]);
    }
    if(arr[value][1] != -1){
        postOrder(arr[value][1]);
    }
    cout<<value<<"\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    while (cin >> a) {
	    v.push_back(a);
    }
    fill(&arr[0][0], &arr[0][0] + 1000004*2, -1);

    root = v[0];
    for(int i=1; i<v.size(); i++){
        go(v[i], root);    
    }
    postOrder(root);

    return 0;

}