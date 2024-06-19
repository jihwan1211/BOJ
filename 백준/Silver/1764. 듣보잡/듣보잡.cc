#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;
map<string, int> mp;
vector<string> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>str;
        mp.insert({str, 1});
    }
    for(int i=0; i<m; i++){
        cin>>str;
        if(mp.find(str) != mp.end()) vec.push_back(str);
    }
    sort(vec.begin(), vec.end());
    
    cout<<vec.size()<<"\n";
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<"\n";
    return 0;
}