#include <bits/stdc++.h>
using namespace std;

int n, num, from, to, ret;
vector<int> vec;

//  투포인터
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    cin>>num;
    sort(vec.begin(), vec.end());
    
    int from_index=0;
    int to_index=n-1;
    while(1){
        if(from_index >= to_index) break;
        from=vec[from_index];
        to=vec[to_index];
        if(from + to < num) from_index++;
        else if(from + to > num) to_index--;
        else {
            ret++;
            to_index--;
        }
    }
    cout<<ret;
    return 0;
}