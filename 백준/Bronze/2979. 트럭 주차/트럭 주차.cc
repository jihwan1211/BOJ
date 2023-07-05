#include<bits/stdc++.h>
using namespace std;

int a[101]={0,};

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int A, B, C;
   cin>>A>>B>>C;
   for(int i=0; i<3; i++){
      int s, l;
      cin>>s>>l;
      for(int j=s; j<l; j++){
         a[j]++;
      }
   }

   int sum=0;
   for(int i=0; i<101; i++){
      if(a[i]==0) continue;
      else if(a[i]==1) sum+=A;
      else if(a[i]==2) sum+=B*2;
      else if(a[i]==3) sum+=C*3;
   }

   cout<<sum;
   return 0;
}