#include <bits/stdc++.h>
using namespace std;

int n, p, d, ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
int arr[10002];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>p>>d;
        pq.push({p, d});
    }

    for(int i=0; i<n; i++){
        int pay = pq.top().first;
        int day = pq.top().second;
        // cout<<pq.top().first<<", "<<pq.top().second<<"\n";
        if(!arr[day]) {
            arr[day] = pay;
        }else{
            int temp_day = day-1;
            while(temp_day){
                if(!arr[temp_day]){
                    arr[temp_day]=pay;
                    break;
                } 
                temp_day--;
            }
        }
        pq.pop();
    }
    for(int i=0; i<10002; i++){
        if(arr[i]) ret+=arr[i];
    }
    cout<<ret;
    return 0;
}