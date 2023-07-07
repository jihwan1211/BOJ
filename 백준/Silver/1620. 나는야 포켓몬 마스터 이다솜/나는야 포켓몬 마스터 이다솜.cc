#include<bits/stdc++.h>
using namespace std;

int N, M;
map<int, string> m;
map<string, int> m2;
string temp;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>N>>M;
   for(int i=0; i<N; i++){
      cin>>temp;
      m.insert({i+1, temp});
      m2.insert({temp, i+1});
   }
   for(int i=0; i<M; i++){
      cin>>temp;
      //영어로 들어올 때
      if((temp[0]>64 && temp[0]<91) || (temp[0]>96 && temp[0]<123)){
         auto it = m2.find(temp);
         cout<< (*it).second<<"\n";
      }else{
         auto it = m.find(stoi(temp));
         cout<< (*it).second<<"\n";
      }
   }
   return 0;

}