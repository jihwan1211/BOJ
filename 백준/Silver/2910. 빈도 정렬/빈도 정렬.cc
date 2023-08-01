#include<bits/stdc++.h>
using namespace std;

int n, c;
//입력된 수, {빈도수, 등장위치}
map<int, pair<int, int>> mp;
//{빈도수, 등장위치}, 입력된 수
map<pair<int, int>, int> mp2;
pair<int, int> pi;
vector<pair<int,int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b){
   if(a.first == b.first) return a.second < b.second;
   return a.first > b.first;
}

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin>>n>>c;

   for(int i=0; i<n; i++){
      int temp;
      cin>>temp;
      if(mp.find(temp) == mp.end() || mp.size()==0){
         //맵에 없으면 추가
         mp.insert({temp, {1, i}});
         mp2.insert({{1, i},temp});
      } else{ // 맵에 입력된 수가 있으면
         //mp에서 입력된 수에 해당하는 
         // {빈도수, 등장위치}를 일단 찾고
         pi=mp[temp];
         //mp2에서 지운다.
         mp2.erase(pi);
         //빈도수를 1 늘려준 후에 
         mp[temp].first++;
         //mp2에 {빈도수, 등장위치}, 입력된 수를 다시 추가해준다
         pi=mp[temp];
         mp2[pi]=temp;
      }
   }
   
   for(auto it : mp2){
      //vec에는 {빈도수, 등장위치}가 담긴다.
      vec.push_back(it.first);
   }

   // 빈도수는 내림차순, 등장위치는 오름차순으로 정렬
   sort(vec.begin(), vec.end(), cmp);

   for(auto it : vec){
      // 빈도수를 기반으로 입력된 수를 출력
      for(int i=0; i<it.first; i++){
         cout<<mp2[it]<<" ";
      }
   }

   return 0;
}