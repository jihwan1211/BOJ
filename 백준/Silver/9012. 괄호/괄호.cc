#include<bits/stdc++.h>
using namespace std;

stack<char> st;

void go(string temp){
    for(int i=0; i<temp.size(); i++){
        if(st.empty()) st.push(temp[i]);
        else if(st.top() == '(' && temp[i] == ')') st.pop();
        else st.push(temp[i]);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        while( !st.empty() ) st.pop();
        go(temp);
        if(st.size()) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
    return 0;
}