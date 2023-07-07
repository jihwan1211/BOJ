#include<bits/stdc++.h>
using namespace std;

int N, K;
int arr[100004];
int sum=-987654321, temp=0;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>N>>K;

   for(int i=0; i<N; i++){
      cin>>arr[i];
   }

   for(int i=0; i<K; i++){
      temp+=arr[i];
   }
   if(temp>sum) sum=temp;
   for(int i=0; i<N-K; i++){
      temp=temp-arr[i]+arr[i+K];
      if(temp>sum) sum=temp;
   }

   cout<<sum;
   return 0;
}