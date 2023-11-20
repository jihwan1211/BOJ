#include <bits/stdc++.h>
using namespace std;

int n, ret=987654321;
int arr[22][22];
int visited[22];
vector<int> vec;

void go(){
    memset(visited, 0, sizeof(visited));
    int temp=0;
    for(int i=0; i<vec.size()-1; i++){
        for(int j=i+1; j<vec.size(); j++){
            visited[vec[i]]=1;
            visited[vec[j]]=1;
            temp = temp + arr[vec[i]][vec[j]] + arr[vec[j]][vec[i]];
        }
    }
    
    int temp2=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i] && !visited[j]){
               temp2 = temp2 + arr[i][j]; 
            }
        }
    }

    ret=min(ret, abs(temp-temp2));
    return;
}

void combi(int start){
    if(vec.size() == n/2){
        go();
        return;
    }
    for(int i=start+1; i<n; i++){
        vec.push_back(i);
        combi(i);
        vec.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    combi(-1);
    cout<<ret;
    return 0;
}