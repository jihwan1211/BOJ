#include<bits/stdc++.h>
using namespace std;

int T, N, arr[34];
string name, group;
map<string, int> m;


int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>T;
   for(int i=0; i<T; i++){
      cin>>N;
      for(int k=0; k<N; k++){
         cin>>name>>group;
         auto it = m.find(group);
         if(it == m.end()){
            m[group]=1;
         }else m[group]++;
      }
      int res=1;
      for(auto it:m){
         res*=(it).second+1;
      }
      cout<<res-1<<"\n";
      m.clear();
   }
   return 0;
}
