#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;
    string temp = "";
    long long ret = 0;
    bool isMinus = false;
    for(int i=0; i<str.length(); i++){
        if(str[i] != '+' && str[i] != '-') {
            temp+=str[i];
        }
        else {
            if(isMinus) ret -= stoi(temp);
            else ret += stoi(temp);
            if(str[i] == '-') isMinus = true;
            temp="";
        }
    }
    if(isMinus) ret -= stoi(temp);
    else ret += stoi(temp); 
    cout<<ret;
    return 0;
}
