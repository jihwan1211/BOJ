#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000004];
vector<pair<int, int>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
        vec.push_back({arr[i], i});
    }

    sort(vec.begin(), vec.end(), less<pair<int, int>>());

    int pos = 0;
    for(int i=0; i<N; i++){
        int index = vec[i].second;
        if(i == 0) {
            arr[index] = i;
            continue;
        }
        if(vec[i].first == vec[i-1].first) arr[index] = pos;
        else {
            pos++;
            arr[index] = pos;
            
        }
    }

    for(int i=0; i<N; i++) cout<<arr[i]<<" ";

    return 0;
}
