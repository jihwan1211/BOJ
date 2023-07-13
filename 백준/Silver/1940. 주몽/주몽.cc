#include<bits/stdc++.h>
using namespace std;

int N, M, cnt=0, base, selected;
int arr[15004];

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin>>N>>M;
   for(int i=0; i<N; i++){
      cin>>arr[i];
   }

   sort(arr, arr+N);

   for(int i=0; i<N-1; i++){
      base=arr[i];
      for(int j=i+1; j<N; j++){
         selected=arr[j];
         if(base+selected==M) cnt++;
         else if(base+selected<M) continue;
         else break;
      }
   }

   cout<<cnt;
   return 0;
}