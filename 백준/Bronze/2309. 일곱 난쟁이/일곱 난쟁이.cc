#include<bits/stdc++.h>
using namespace std;

vector<int> h;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   for(int i=0; i<9; i++) {
      int temp;
      cin>>temp;
      h.push_back(temp);
   }

   sort(h.begin(), h.end());

   do{
      int sum=0;
      for(int i=0; i<7; i++) sum+=h[i];
      if(sum==100) break;
   }while(next_permutation(h.begin(), h.end()));

   for(int i=0; i<7; i++) cout<<h[i]<<"\n";
   return 0;
}
