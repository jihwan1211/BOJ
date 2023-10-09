#include<bits/stdc++.h>
using namespace std;

int n;
string min_ret="9876543210";
string max_ret="01";
char arr[10];
vector<int> vec;

string m(string a, string b){
    if(a>b) return a;
    else return b;
}

string mini(string a, string b){
    if(a>b) return b;
    else return a;
}

void check(){
    for(int i=0; i<n; i++){
        if(arr[i] == '>'){
            if((int)vec[i] < (int)vec[i+1]) return;
        }else{
            if((int)vec[i] > (int)vec[i+1]) return;
        }
    }
    string temp="";
    for(int i=0; i<n+1; i++){
        temp+=to_string(vec[i]);
    }
    max_ret = m(max_ret, temp);
    min_ret = mini(min_ret, temp);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<10; i++){
        vec.push_back(i);
    }

    do{
        check();
    }while(next_permutation(vec.begin(), vec.end()));
    cout<<max_ret<<"\n"<<min_ret;
    return 0;
}