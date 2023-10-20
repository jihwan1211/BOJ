#include<bits/stdc++.h>
using namespace std;

int n, k, ret=-1;
int learn[27];
vector<string> vec;
vector<int> w;

void go(){
    int learn[27];
    int cnt=0;
    memset(learn, 0, sizeof(learn));
    for(int i=0; i<w.size(); i++){
        // cout<<w[i]<<" ";
        learn[w[i]]=1;
    }
    // cout<<"\n";
    for(int i=0; i<vec.size(); i++){
        // if(i+'a'=='a' || i+'a' == 'n' || i+'a' == 'i' || i+'a'=='c' || i+'a'=='t') continue;
        bool flag=true;
        string word=vec[i];
        for(int j=0; j<word.size(); j++){
            if(word[j]=='a' || word[j]== 'n' || word[j]== 'i' || word[j]=='c' || word[j]=='t') continue;
            if(!learn[word[j]-'a']) {
                flag=false;
                break;
            }
        }
        if(flag) cnt++;
    }
    ret=max(ret, cnt);
}

void combi(int start){
    if(w.size()==k-5){
        go();
        return;
    }
    for(int i=start+1; i<27; i++){
        if(i+'a'=='a' || i+'a' == 'n' || i+'a' == 'i' || i+'a'=='c' || i+'a'=='t') continue;
        // cout<<i+'a'<<" ";
        w.push_back(i);
        combi(i);
        w.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;

    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        vec.push_back(temp);
    }

    if(k<5){
        cout<<0;
        return 0;
    }
    combi(-1);
    // for(int i=0; i<(1<<27); i++){
    //     memset(learn, 0, sizeof(learn));
    //     int learnedWord=0;
    //     for(int j=0; j<27; j++){
    //         if(i&(1<j)){
    //             learn[j]=1;
    //             learnedWord++;
    //         }
    //     }
    //     if(learnedWord != 6) continue;
    //     int cnt=0;
    //     for(int w=0; w<n; w++){
    //         bool flag=true;
    //         string word=vec[w];
    //         for(int b=0; b<word.size(); b++){
    //             if(!learn[word[b]-'a']) {
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         if(flag) cnt++;
    //     }
    //     ret=max(ret, cnt);
    // }
    cout<<ret;
    return 0;
}