#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> vec;
string num;
bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void check(){
     while(num.size()){
        if(num.size()==1) return;
        if(num[0] == '0'){
            num.erase(0, 1);
        }else {
            break;
        }
    }
    return ;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    num="";
    cin>>N;

    for(int i=0; i<N; i++){
        string temp;
        cin>>temp;
        num="";
        for(int j=0; j<temp.length(); j++){
            // 숫자라면
            if(temp[j] < 97 || temp[j] >122){
                num+=temp[j];
            } else{ //알파벳이면
                check();
                if(num.length()) vec.push_back(num);
                num="";
            }
        }
        check();
        if(num.length()) vec.push_back(num);
    }

    sort(vec.begin(), vec.end(), cmp);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<"\n";
    }
    return 0;
}