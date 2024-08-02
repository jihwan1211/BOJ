#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> st;

bool isOper(char c){
    if(c == '+' || c== '-' || c=='*' || c=='/' || c == '(' || c== ')' ) return true;
    else return false;
}

// true -> stackitem보다 우선 순위 낮음
// false -> stackitem보다 우선 순위 높음
bool decideFirst(char stackItem, char oper){
    if(oper == '+' || oper == '-'){
        // if(stackItem == '*' || stackItem == '/' || stackItem == '(') return true;
        return true;
    }else {
        if(stackItem == '(' || stackItem == '*' || stackItem == '/') return true;
        else return false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str;
    for(int i=0; i<str.length(); i++){
        if(!isOper(str[i])) cout<<str[i];
        else{
            if(str[i] == '(') st.push(str[i]);
            else if(str[i] == ')'){
                while(st.size()){
                    char item = st.top();
                    if(item == '(') {
                        st.pop();
                        break;
                    }else{
                        cout<<item;
                        st.pop();
                    }
                }
            }else {
                while(1){
                    if(!st.size()) {
                        st.push(str[i]);
                        break;
                    }    
                    char item = st.top();
                    if(decideFirst(item, str[i])){
                        if(item == '(') {
                            st.push(str[i]);
                            break;
                        }else{
                            cout<<item;
                            st.pop();
                        }
                    }else {
                        st.push(str[i]);
                        break;
                    }
                              
                }
            }
        }
    }
    while(st.size()){
        cout<<st.top();
        st.pop();
    }
 
    return 0;
}

