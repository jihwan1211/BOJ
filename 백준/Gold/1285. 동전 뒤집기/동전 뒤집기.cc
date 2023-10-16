#include<bits/stdc++.h>
using namespace std;

int n, ret=987654321;
int arr[21][21];
int row[21];

void go(){
    int num=0;
    int temp[21][21];
    memcpy(temp, arr, sizeof(arr));
    for(int i=0; i<n; i++){
        if(row[i]) {
            for(int j=0; j<n; j++){
                if(temp[i][j]) temp[i][j]=0;
                else temp[i][j]=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        int t=0;
        for(int j=0; j<n; j++){
            if(!temp[j][i]) t++;
        }
        if(n/2 < t){
            for(int j=0; j<n; j++){
                if(temp[j][i]) temp[j][i]=0;
                else temp[j][i]=1;
            }
            num+=n-t;
            continue;
        }
        num+=t;
    }
    ret=min(ret, num);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<n; j++){
            if(temp[j]=='T') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }

    for(int i=0; i<(1<<n); i++){
        for(int k=0; k<n; k++){
            if(i&(1<<k)) row[k]=1;
        }
        go();
        memset(row, 0, sizeof(row));
    }
    cout<<ret;
    return 0;
}