#include <bits/stdc++.h>
using namespace std;

int N, ret=-1;
int arr[200004];
int fruit[11];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    int left = 0;
    int fruit_num = 0;
    int temp_sum = 0;

    for(int i=0; i<N; i++){
        int cur_fruit = arr[i];
        //새로운 과일을 만났을 때
        if(fruit_num == 2 && fruit[cur_fruit] == 0){
            ret=max(ret, temp_sum);
            while(fruit_num >= 2){
                fruit[arr[left]]--;
                temp_sum--;
                if(fruit[arr[left]] == 0) fruit_num--;
                left++;
            }
            fruit[cur_fruit]++;
            temp_sum++;
            fruit_num++;
        }else{
            if(fruit[cur_fruit] == 0) {
                fruit[cur_fruit]++;
                temp_sum++;
                fruit_num++;
            }else{
                fruit[cur_fruit]++;
                temp_sum++;
            }
        }
    }
    ret=max(ret, temp_sum);
    cout<<ret;
    return 0;
}