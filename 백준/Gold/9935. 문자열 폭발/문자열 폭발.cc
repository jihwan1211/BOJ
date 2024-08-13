#include <bits/stdc++.h>
using namespace std;

string str, bomb, temp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str>>bomb;
    
    for(int i=0; i<str.length(); i++){
        temp.push_back(str[i]);
        if(temp.size() >= bomb.size()){
            // str이 bomb의 마지막 문자와 같은 경우 
            if(str[i] == bomb[bomb.size()-1]){
                string bombCandidate = temp.substr(temp.size()-bomb.size(), bomb.size());
                if(bombCandidate == bomb){
                    temp.erase(temp.size()-bomb.size(), bomb.size());
                }
            }
        }
    }
    if(temp.size()) cout<<temp;
    else cout<<"FRULA";
    return 0;
}