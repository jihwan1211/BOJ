#include<bits/stdc++.h>
using namespace std;

int a[26] = {0,};

int main() {
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   string input;
   cin>>input;

   for(int i=0; i<input.size(); i++){
      a[input[i]-97]++;
   }

   for(int i:a) cout<<i<<" ";
   return 0;
}
