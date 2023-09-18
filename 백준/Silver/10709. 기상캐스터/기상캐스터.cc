#include<bits/stdc++.h>
using namespace std;

int arr[104][104];
int ret[104][104];
int H, W;
int cloudPos=1000;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>H>>W;
    for(int i=0; i<H; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<temp.size(); j++){
            if(temp[j] == 'c') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }

    for(int i=0; i<H; i++){
        cloudPos=1000;
        for(int j=0; j<W; j++){
            if(arr[i][j]==1){
                cloudPos=j;
                ret[i][j]=0;
            } else{
                if(cloudPos > j || cloudPos==1000) ret[i][j]=-1;
                else{
                    ret[i][j] = j-cloudPos;
                }
            }
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}