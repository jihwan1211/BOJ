#include <bits/stdc++.h>
using namespace std;

int N, M, T, temp, person, cnt;
vector<int> truth;
vector<int> arr[52];
vector<int> party[52];
int visited[52];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    cin>>T;
    for(int i=0; i<T; i++) {
        cin>>temp;
        truth.push_back(temp);
    }

    for(int i=1; i<=M; i++){
        cin>>temp;
        for(int j=0; j<temp; j++){
            cin>>person;
            arr[person].push_back(i);
            party[i].push_back(person);
        }
    }

    queue<int> q;
    for(int i=0; i<truth.size(); i++){// visited[truth[i]] = 1;
        q.push(truth[i]);
    }

    while(q.size()){
        person  = q.front();
        q.pop();
        if(visited[person]) continue;
        visited[person] = 1;
        //진실을 아는 사람이 참여하는 파티
        for(int i=0; i<arr[person].size(); i++){
            int party_num = arr[person][i];
            // n번 파티에 참여하는 사람들
            for(int j=0; j<party[party_num].size(); j++){
                int in_party_person = party[party_num][j];
                if(visited[in_party_person]) continue;
                q.push(in_party_person);
            }
        }
    }

    for(int i=1; i<=M; i++){
        bool flag = false;
        for(int j=0; j<party[i].size(); j++){
            if(visited[party[i][j]]) {
                flag = true;
                break;
            }
        }
        if(!flag) cnt++;
    }

    cout<<cnt;
    return 0;
}