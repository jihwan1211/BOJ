#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<char> st;
    
    while(1){
        bool flag=true;
        string temp;
        getline(cin, temp);
        if(temp == "."){ 
            break;
        }
        for(int i=0; i<temp.size(); i++){
            if(temp[i] == '(' || temp[i] == '[') st.push(temp[i]);
            else if(temp[i] == ')'){
                if(st.size() && st.top()=='(') {
                    st.pop();
                    continue;
                } else {flag=false; break;}
            }else if(temp[i] == ']'){
                if(st.size() && st.top()=='['){
                    st.pop();
                    continue;
                }else {flag=false; break;}
            }
        }
        if(flag && st.size() == 0) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
        while(st.size()) st.pop();
    }
    return 0;
}