#include <bits/stdc++.h>
using namespace std;

int n, ret, maxVal;
int arr[1004], cnt[1004], pos[1004];
vector<int> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cnt[0]=1;
    fill(&pos[0], &pos[1004], -1);
    for(int i=0; i<n; i++){
        maxVal = 0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && cnt[j] > maxVal) {
                maxVal = cnt[j];
                pos[i]=j;
            }
        }
        cnt[i] = maxVal+1;
        ret=max(ret, cnt[i]);
    }

    int start = 0;
    for(int i=n; i>=0; i--){
        if(cnt[i] == ret) {
            start=i;
        }
    }
    
    while(1){
        vec.push_back(arr[start]);
        start=pos[start];
        if(start == -1) break;
    }
    
    reverse(vec.begin(), vec.end());
    cout<<ret<<"\n";
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
  
    return 0;
}