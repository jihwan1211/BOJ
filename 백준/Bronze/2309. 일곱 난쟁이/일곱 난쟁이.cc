#include<bits/stdc++.h>
using namespace std;

vector<int> h;

void combi(int start, vector<int> b){ 
   if(b.size() == 7){
      int sum=0;
      for(int i=0; i<7; i++){
         sum+=b[i];
      }
      if(sum==100){
           for(int i=0; i<7; i++) cout<<b[i]<<"\n";
           exit(0);
      }
      return; 
   }

   for(int i = start + 1; i < 9; i++){ 
      b.push_back(h[i]);
      combi(i, b);
      b.pop_back();
    }
   return; 
}

int main(){
   for(int i=0; i<9; i++) {
      int temp;
      cin>>temp;
      h.push_back(temp);
   }

   sort(h.begin(), h.end());
   vector<int> b;
   combi(-1, b);

   return 0;
}