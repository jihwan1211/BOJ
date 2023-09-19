#include<bits/stdc++.h>
using namespace std;

int split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) {
            token = input.substr(0, pos);
           ret.push_back(token);
           input.erase(0, pos + delimiter.length());
    } 
    ret.push_back(input); 
    int time = stoi(ret[1]) + stoi(ret[0])*60;
    return time;
}

string aprint(int a){ 
    string d = "00" + to_string(a / 60); 
    string e = "00" + to_string(a % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int team1=0, team2=0;
    int leadTeam, leadStartTime=0;
    int n;
    int team1Lead=0, team2Lead=0;

    cin>>n;
    for(int i=0; i<n; i++){
        int scoredTeam;
        string time;
        cin>>scoredTeam>>time;

        // 최초득점
        if(!team1 && !team2){
            leadStartTime = split(time, ":");
            if(scoredTeam == 1){
                team1++;
                leadTeam = 1;
            }else if(scoredTeam == 2){
                team2++;
                leadTeam = 2;
            }
            continue;
        }

        //득점 상황
        if(scoredTeam == 1){
            team1++;
            if(!leadTeam) {
                leadTeam = 1;
                leadStartTime = split(time, ":");
            }
        }else if(scoredTeam == 2){
            team2++;
            if(!leadTeam) {
                leadTeam = 2;
                leadStartTime = split(time, ":");
            }
        }

        // 동점이 될 때
        if(team1 == team2){
            leadTeam=0;
            if(scoredTeam == 1){
                int temp = split(time, ":");
                team2Lead += temp - leadStartTime;
            } else{
                int temp = split(time, ":");
                team1Lead += temp - leadStartTime;
            }
        }
    }

    if(leadTeam == 1){
        team1Lead += 48*60 - leadStartTime;
    } else if(leadTeam == 2){
        team2Lead += 48*60 - leadStartTime;
    } 

    cout<<aprint(team1Lead)<<"\n";
    cout<<aprint(team2Lead)<<"\n";

    return 0;
}