#include<bits/stdc++.h>
using namespace std;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   string s, temp;
   cin>>s;
   temp=s;
   reverse(temp.begin(), temp.end());
   if(s==temp) cout<<1;
   else cout<<0;
   return 0;
}