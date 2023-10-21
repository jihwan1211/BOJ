#include<bits/stdc++.h>
using namespace std;

int m, num;
string method;
string temp;
long long s;

void split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    } 
    ret.push_back(input);
    method=ret[0];
    if(ret.size()>1) num=stoi(ret[1]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>m;

    for(int i=0; i<=m; i++){

        getline(cin, temp);
        split(temp, " ");
        if(method=="add"){
            s|=(1<<num);
        }else if(method=="remove"){
            s&=~(1<<num);
        }else if(method=="check"){
            if(s&(1<<num)) cout<<1<<"\n";
            else cout<<0<<"\n";
        }else if(method=="toggle"){
            s^=(1<<num);
        }else if(method=="all"){
            s=(1<<21)-1;
        }else {
            s=0;
        }
    }
    return 0;
}

