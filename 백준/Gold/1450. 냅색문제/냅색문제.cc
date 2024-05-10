#include <bits/stdc++.h>
using namespace std;

int n, c;
int arr[34];
long long ret;
vector<int> vec, vec2;

void go(int here, int end, int sum){
    if(sum > c) return;
    if(here > end){
        vec.push_back(sum);
        return;
    }
    go(here+1, end, sum+arr[here]);
    go(here+1, end, sum);
    return;
}

void go2(int here, int end, int sum){
    if(sum > c) return;
    if(here > end){
        vec2.push_back(sum);
        return;
    }
    go2(here+1, end, sum+arr[here]);
    go2(here+1, end, sum);
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>c;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    go(0, n/2-1, 0);
    go2(n/2, n-1, 0);

    sort(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());

    for(int i=0; i<vec.size(); i++){
        if(c-vec[i] >= 0) ret+= ((int)(upper_bound(vec2.begin(), vec2.end(), c-vec[i]) - vec2.begin()));
    }
    cout<<ret;
    return 0;
}