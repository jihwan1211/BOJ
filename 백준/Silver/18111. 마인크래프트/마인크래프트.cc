#include <bits/stdc++.h>
using namespace std;

int N,M,B, max_height, min_height=257, timee = 987654321, ret = 987654321;
int arr[504][504];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            max_height = max(max_height, arr[i][j]);
            min_height = min(min_height, arr[i][j]);
        }
    }

    for(int h=min_height; h<=max_height; h++){
        int cnt=B;
        int temp_time = 0;
        bool flag = true;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(h == arr[i][j]) continue;
                else if(h<arr[i][j]) {
                    cnt += arr[i][j] - h;
                    temp_time += 2*(arr[i][j] - h);
                }else {
                    cnt -= h-arr[i][j];
                    temp_time += h-arr[i][j];
                }
            }
        }
        if(cnt>=0) {
            if(temp_time <= timee){
                timee = temp_time;
                ret = h;
            }
        }
    }

    cout<<timee<<" "<<ret;
    return 0;
}
