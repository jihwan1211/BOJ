#include <bits/stdc++.h>
using namespace std;

priority_queue<long long, vector<long long>, less<long long>> lq; // 최대힙
priority_queue<long long, vector<long long>, greater<long long>> gq; // 최소힙

map<long long, int> mp1;
map<long long, int> mp2;

int t, n, num;
string str;

void init(){
    while(lq.size()) lq.pop();
    while(gq.size()) gq.pop();
    mp1.clear();
    mp2.clear();
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++){
        init();
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>str>>num;
            if(str == "I"){
                lq.push(num);
                gq.push(num);
            } else{
                if(num == 1) {
                    while(1){
                        if(lq.size()){
                            long long temp = lq.top();
                            if(mp2.find(temp) != mp2.end() && mp2[temp] > 0) {
                                lq.pop();
                                mp2[temp]--;
                                continue;
                            }else{
                                lq.pop();
                                mp1[temp] ++;
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                }
                else {
                    while(1){
                        if(gq.size()){
                            long long temp = gq.top();
                            if(mp1.find(temp) != mp1.end() && mp1[temp] > 0) {
                                gq.pop();
                                mp1[temp]--;
                                continue;
                            }else{
                                gq.pop();
                                mp2[temp]++;
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        while(lq.size()){
            long long temp = lq.top();
            if(mp2.find(temp) != mp2.end() && mp2[temp] > 0){
                lq.pop();
                mp2[temp]--;
            }else{
                break;
            }
        }
        while(gq.size()){
            long long temp = gq.top();
            if(mp1.find(temp) != mp1.end() && mp1[temp] > 0){
                gq.pop();
                mp1[temp]--;
            }else{
                break;
            }
        }
        if(!lq.size() && !gq.size()) cout<<"EMPTY\n";
        else cout<<lq.top()<<" "<<gq.top()<<"\n";
    }
    return 0;

}