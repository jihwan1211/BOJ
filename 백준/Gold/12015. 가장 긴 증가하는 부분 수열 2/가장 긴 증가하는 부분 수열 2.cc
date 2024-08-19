#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000004];
vector<int> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<N; i++){
        if(!vec.size()) vec.push_back(arr[i]);
        else{
            if(arr[i] > vec[vec.size()-1]) vec.push_back(arr[i]);
            else if(arr[i] == vec[vec.size()-1]) continue;
            else {
                int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
                vec[idx] = arr[i];
            }
        }
    }

    cout<<vec.size();
    return 0;
}