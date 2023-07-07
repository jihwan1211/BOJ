#include<bits/stdc++.h>
using namespace std;

string s;

void ROT13(){
   for(int i=0; i<s.size(); i++){
      int temp=0;
      if(s[i]>64 && s[i]<91){
         temp=s[i]+13;
         if(temp>90) s[i]=temp-91+'A';
         else s[i]=temp;
      } else if(s[i]>96 && s[i] < 123){
         temp+=s[i]+13;
         if(temp > 122) s[i]=temp-123+'a';
         else s[i]=temp;
      }
   }
};


int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   getline(cin, s);
   ROT13();
   cout<<s;
   return 0;
}