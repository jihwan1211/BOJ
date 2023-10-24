#include<bits/stdc++.h>
using namespace std;

int t, n;
bool err=false;
bool flag = true;
string func, temp;
deque<int> de;

void go(){
    string num;
    for(int i=0; i<temp.size(); i++){
        if(isdigit(temp[i])) num+=temp[i];
        if(temp[i]==',') {
            de.push_back(stoi(num));
            num="";
        }
    }
    if(num.size()) de.push_back(stoi(num));
}

void solve(){
    for(int i=0; i<func.size(); i++){
        if(de.size()==0 && func[i]=='D') {
            err=true;
            return;
        }
        if(func[i] == 'R') flag=!flag;
        else {
            if(flag) de.pop_front();
            else de.pop_back();
        }
    }
}

void print(){
    if(err) {
        cout<<"error\n";
        return;
    }
    cout<<"[";
    if(flag){
        for(int i=0; i<de.size(); i++){
            cout<<de[i];
            if(i!=de.size()-1)cout<<",";
        }
    }else{
        for(int i=de.size()-1; i>=0; i--){
            cout<<de[i];
            if(i!=0)cout<<",";
        }
    }
    cout<<"]\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>func>>n>>temp;
        go();
        solve();
        print();
        de.clear();
        err=false;
        flag=true;
    }   
    return 0;
}
