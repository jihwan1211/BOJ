#include <bits/stdc++.h>
using namespace std;

double posA, posB;
double cnt;
double ret;
double a[20];
double b[20];
vector<int> vec;

double calc(double pos, int t){
    double temp =1.0;
    for(int i=0; i<t; i++){
        temp*=pos;
    }
    return temp;
}

void combi(int start, int size){
    if(vec.size() == size){
        cnt = cnt + 1.0;
        return;
    }
    for(int i=start+1; i<=17; i++){
        vec.push_back(i);
        combi(i, size);
        vec.pop_back();
    }
}

void go(){
    for(int i=0; i<=18; i++){
        combi(-1, i);
        if(posA == 1.0 || posB == 1.0){
            if(posA == 1.0){
                if(i == 18) a[i] = 1;
                else a[i] = 0;
            }else{
                 a[i] = (double)cnt * calc(posA, i)*calc(1-posA, 18-i);
            }
            if(posB == 1.0){
                if(i==18) b[i] = 1;
                else b[i] = 0;
            }else{
                b[i] = (double)cnt * calc(posB, i)*calc(1-posB, 18-i);
            }
            cnt=0;
            vec.clear();
            continue;
        }
        // a팀 득점 확률 계산
        a[i] = (double)cnt * calc(posA, i)*calc(1-posA, 18-i);
        //b 팀 득점 확률 계산
        b[i] = (double)cnt * calc(posB, i)*calc(1-posB, 18-i);
        // cout<<cnt<<"\n";
        vec.clear();
        cnt=0;
    }
    
    double temp_a = a[2] + a[3] + a[5] + a[7] + a[11] + a[13] + a[17];
    double temp_b = b[2] + b[3] + b[5] + b[7] + b[11] + b[13] + b[17];
    ret = a[2] + a[3] + a[5] + a[7] + a[11] + a[13] + a[17] + b[2] + b[3] + b[5] + b[7] + b[11] + b[13] + b[17] - (temp_a*temp_b);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin>>posA>>posB;

    posA = posA*0.01;
    posB = posB*0.01;
    // cout<<posA<<" "<<posB<<"\n";
    go();
    // double temp=0;
    // for(int i=0; i<=18; i++){
    //     temp+= a[i];
    // }
    // cout<<temp<<"\n";
    printf("%.9lf", ret);
    // cout<<ret;

    return 0;
}