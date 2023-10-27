#include <bits/stdc++.h>
using namespace std;

string str;
stack<pair<int, char>> st;
int ret, cnt, n;
int arr[200002];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>str;
    for(int i=0; i<n; i++){
        if(st.empty()) {
            st.push({i, str[i]});
            continue;
        }

        if(str[i] == '(') st.push({i, str[i]});
        else {
            if(st.top().second == '(') {
                arr[st.top().first]=1;
                arr[i]=1;
                st.pop();
            }
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i]==1) cnt++;
        else cnt=0;
        ret=max(ret, cnt);
    }
    cout<<ret;
    return 0;
}
