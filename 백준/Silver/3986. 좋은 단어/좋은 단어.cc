#include<bits/stdc++.h>
using namespace std;

int N, cnt=0;
string input;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>N;
   for(int i=0; i<N; i++){
      cin>>input;
      stack<char> st;
      for(int j=0; j<input.size(); j++){
         if(st.empty()) st.push(input[j]);
         else if(!st.empty()){
            if(st.top() == input[j]) st.pop();
            else st.push(input[j]);
         }
      }
      if(!st.size()) cnt++;
   }

   cout<<cnt;
   return 0;
}