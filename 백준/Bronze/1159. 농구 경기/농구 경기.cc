#include<bits/stdc++.h>
using namespace std;

int cnt[26]={0,};

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int N;
   cin>>N;
   for(int i=0; i<N; i++){
      string temp;
      cin>>temp;
      cnt[(int)(temp[0]-'a')]++;
   }

   bool flag = false;
   for(int i=0; i<26; i++){
      if(cnt[i]>4){ 
         cout<<(char)(i+'a');
         flag=true;
      }
   }

   if(!flag) cout<<"PREDAJA";
   return 0;
}