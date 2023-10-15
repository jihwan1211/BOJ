#include<bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
// int p, f, s, v, price;
int ret=987654321;
int arr[16][6];
vector<int> vec;
// vector<int> ans;
string ans="";

string go(string ans, string temp){
    if(ans < temp) return ans;
    else return temp;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>mp>>mf>>ms>>mv;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }

    for(int i=0; i<(1<<n); i++){
        int p=0, f=0, s=0, v=0, price=0;
        string temp="";
        vec.clear();
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                p+=arr[j][0];
                f+=arr[j][1];
                s+=arr[j][2];
                v+=arr[j][3];
                price+=arr[j][4];
                // vec.push_back(j);
                temp+=j;
            }
        }
        if(p>=mp && f>=mf && s>=ms && v>=mv){
            if(ret==price){
                // 사전순으로 앞서는 것
                ans=go(temp, ans);
            }
            else if(ret>price){
                // ans.clear();
                ret=min(ret, price);
                // for(int k=0; k<vec.size(); k++){
                //     ans.push_back(vec[k]);
                // }
                ans=temp;
            }
        }
    }
    if(ret==987654321) cout<<-1;
    else{
        cout<<ret<<"\n";
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]+1<<" ";
        }
    }
    return 0;
}