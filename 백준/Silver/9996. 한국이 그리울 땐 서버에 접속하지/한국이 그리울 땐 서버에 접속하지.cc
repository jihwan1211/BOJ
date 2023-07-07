#include<bits/stdc++.h>
using namespace std;

int N;
string pattern1="", pattern2="", temp="";
string front, back;
bool flag=false;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin>>N;
   cin>>temp;
   for(int i=0; i<temp.size(); i++){
      if(temp[i]==42) {
         flag=true;
         continue;
      }
      if(!flag) pattern1+=temp[i];
      else pattern2+=temp[i];
   }

   for(int i=0; i<N; i++){
      front="", back="";
      string input;
      cin>>input;
      if(input.size()>=pattern1.size()) {
         front = input.substr(0, pattern1.size());
         input.erase(0, pattern1.size());
      }
      if(input.size()>=pattern2.size()) back = input.substr(input.size()-pattern2.size(), pattern2.size());
      if(front==pattern1 && back==pattern2) cout<<"DA"<<"\n";
      else cout<<"NE"<<"\n";
   }

   return 0;
}