#include<bits/stdc++.h>
using namespace std;

int n, m, j, cnt=0;
int arr[24];

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>n>>m>>j;
   for(int i=0; i<j; i++){
      cin>>arr[i];
   }

   int left=1, right=left+m-1;
   int move=0;

   for(int i=0; i<j; i++){
      if(arr[i]>=left && arr[i]<=right) continue;
      else {
         if(arr[i]<left){
            move=left-arr[i];
            left-=move;
            right-=move;
            cnt+=move;
         }else{
            move=arr[i]-right;
            right+=move;
            left+=move;
            cnt+=move;
         }
      }
   }

   cout<<cnt;
   return 0;
   
}