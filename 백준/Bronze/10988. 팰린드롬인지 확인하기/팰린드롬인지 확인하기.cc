#include<bits/stdc++.h>
using namespace std;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   string s;
   stack<char> st;
   bool flag=true;
   cin>>s;
   for(int i=0; i<s.size(); i++){
     if(i<s.size()/2) {
         st.push(s[i]);
         continue;
      }
     if(s.size()%2==1 && i==s.size()/2) continue;
     else{
      if(st.top()!=s[i]) {
         flag=false;
         break;
      }else{
         if(st.size()) st.pop();
      }
     }
   }

  cout<<flag;
  return 0;
}