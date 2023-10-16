#include<bits/stdc++.h>
using namespace std;

int n, ret=987654321;
int arr[21][21];
int row[21];
int col[21];

void go(){
    int num=0;
    int temp[21][21];
    memcpy(temp, arr, sizeof(arr));
    for(int i=0; i<n; i++){
        // int cnt=row[i];
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
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!temp[i][j]) num++;
        }
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

    // for(int i=0; i<n; i++){
    //     int cnt=0;
    //     for(int j=0; j<n; j++){
    //         if(!arr[i][j]) cnt++;
    //     }
    //     row[i]=cnt;
    // }

    // for(int i=0; i<n; i++){
    //     if(n/2 >= row[i]) continue;
    //     else{
    //         for(int j=0; j<n; j++){
    //             if(arr[i][j]) arr[i][j]=0;
    //             else arr[i][j]=1;
    //         }
    //     }
    // }

    // for(int i=0; i<n; i++){
    //     int cnt=0;
    //     for(int j=0; j<n; j++){
    //         if(arr[j][i]) cnt++;
    //     }
    //     col[i]=cnt;
    // }

    // for(int i=0; i<n; i++){
    //     if(n/2 >= col[i]) continue;
    //     else{
    //         for(int j=0; j<n; j++){
    //             if(arr[i][j]) arr[i][j]=0;
    //             else arr[i][j]=1;
    //         }
    //     }
    // }

    // int res=0;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(!arr[i][j]) res++;
    //     }
    // }
    // cout<<res;

    for(int i=0; i<(1<<n); i++){
        for(int k=0; k<n; k++){
            if(i&(1<<k)) row[k]=1;
        }
        go();
        memset(row, 0, sizeof(row));
        // for(int j=0; j<(1<<n); j++){
        //     for(int k=0; k<n; k++){
        //         // 열에서 켜있는 비트 찾기
        //         if(i&(1<<k)){
        //             row[k]=1;
        //         }
        //         if(j&(1<<k)){
        //             col[k]=1;
        //         }
        //     }
        //     go();
        //     memset(row, 0, sizeof(row));
        //     memset(col, 0, sizeof(col));
        // }
    }
    cout<<ret;
    return 0;
}