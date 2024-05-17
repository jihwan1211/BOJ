#include <bits/stdc++.h>
using namespace std;

int n, temp;
int arr[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string max_dp[101];
string min_dp[101];

string getMin(string a, string b){
    if(a.length() > b.length()) return b;
    else if(a.length() < b.length()) return a;
    else {
        if(a > b) return b;
        else return a;
    }
}

string getMax(string a, string b){
    if(a.length() > b.length()) return a;
    else if(a.length() < b.length()) return b;
    else {
        if(a > b) return a;
        else return b;
    }
}

void go_min(int target){
    string ret;
    for(int i=0; i<100; i++){
        ret+="1";
    }
    for(int i=2; i<=target-2; i++){
        if(min_dp[i] == "0") continue;
        if(i == 6){
            ret=getMin(ret, "6" + min_dp[target-i]);
        }
        if(target - i == 6){
            ret=getMin(ret, min_dp[i] + "0");
        }
        ret = getMin(ret, min_dp[i] + min_dp[target-i]);
    }
    min_dp[target] = ret;
}


void go_max(int target){
    string ret = "0";
    for(int i=2; i<=target-2; i++){
        if(max_dp[i] == "0") continue;
        ret = getMax(ret, max_dp[i] + max_dp[target-i]);
    }
    max_dp[target] = ret;
}

void findMin(){
    // min_dp[0]=-1;
    // min_dp[1]=-1;
    min_dp[2]="1";
    min_dp[3]="7";
    min_dp[4]="4";
    min_dp[5]="2";
    // 여기가 문제다.
    min_dp[6]="6";
    min_dp[7]="8";

    for(int i=8; i<=100; i++){
        go_min(i);
    }
    return;
}

void findMax(){
    max_dp[2] = "1";
    max_dp[3] = "7";
    for(int i=4; i<=100; i++){
        go_max(i);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    findMin();
    findMax();
    for(int i=0; i<n; i++){
        cin>>temp;

        cout<<min_dp[temp]<<" ";
        cout<<max_dp[temp]<<"\n";
    }
    return 0;
}