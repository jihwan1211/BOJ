#include<bits/stdc++.h>
using namespace std;

int k;
vector<int> vec;
vector<int> adj[2000];
queue<int> q;

int go(int size, int mid){
   if(size != 3){
        int left = go(size/2, mid-(size/4)-1);
        int right = go(size/2, mid+(size/4)+1);
        adj[vec[mid]].push_back(left);
        adj[vec[mid]].push_back(right);
   }else{
    int left=vec[mid-1];
    int midi=vec[mid];
    int right=vec[mid+1];
    adj[midi].push_back(left);
    adj[midi].push_back(right);
    return midi;
   }
   return vec[mid];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>k; 
    int size=pow(2,k)-1;
    for(int i=0; i<size; i++){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }

    int mid = go(size, size/2);

    // for(int i=0; i<size; i++){
    //     cout<<vec[i]<<" ";
    // }

    // cout<<mid<<"\n";
    q.push(mid);
    while(q.size()){
        // int num = q.front();
        int size = q.size();
        for(int i=0; i<size; i++){
            int num = q.front();
            cout<<num<<" ";
            q.pop();
            if(adj[num].size()){
                q.push(adj[num][0]);
                q.push(adj[num][1]);
            }
        }
        cout<<"\n";
    }
    return 0;
}