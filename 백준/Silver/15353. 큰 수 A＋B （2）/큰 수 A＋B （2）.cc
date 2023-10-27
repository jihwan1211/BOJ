#include <bits/stdc++.h>
using namespace std;

string str1, str2;

string go(string str, int len){
    reverse(str.begin(), str.end());
    int len2 = str.size();
    for(int i=0; i<len - len2; i++){
        str+='0';
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>str1>>str2;

    if(str1.size() > str2.size()) str2= go(str2, str1.size());
    else str1 = go(str1, str2.size());

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    
    int temp=0;
    int carry=0;
    int calc=0;
    string ret ="";
    for(int i=0; i<str1.size(); i++){
        if(carry) temp = (str1[i]-'0')+(str2[i]-'0')+ carry;
        else temp= (str1[i]-'0')+(str2[i]-'0');

        carry=0;

        if(temp >= 10){
            carry=temp/10;
            calc = temp%10;
        }else calc=temp;
        ret+=to_string(calc);
    }
    if(carry) ret+=to_string(carry);
    reverse(ret.begin(), ret.end());
    cout<<ret;
    return 0;
}