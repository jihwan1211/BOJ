#include <bits/stdc++.h>
using namespace std;

int n, ret, temp;
vector<int> vec;
int arr[1004];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), less<int>());

    arr[0] = vec[0];
    for(int i=1; i<n; i++){
        arr[i] = arr[i-1] + vec[i];
    }
    for(int i=0; i<n; i++) ret+=arr[i];
    cout<<ret;
    return 0;
}