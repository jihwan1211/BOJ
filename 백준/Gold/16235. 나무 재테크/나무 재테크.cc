#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, z;
int arr[12][12], a[12][12];
vector<int> vec[12][12];
int die[12][12], dieAge[12][12];

void spring(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vec[i][j].size()) continue;
            sort(vec[i][j].begin(), vec[i][j].end());
            for(int t=0; t<vec[i][j].size(); t++){
                if(arr[i][j] >= vec[i][j][t]){
                    arr[i][j] -= vec[i][j][t];
                    vec[i][j][t]++;
                }else{
                    if(die[i][j] == -1){
                        die[i][j] = t;
                    }
                    dieAge[i][j] += vec[i][j][t]/2;
                }
            }
        }
    }
}

void summer() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(die[i][j] != -1){
                vec[i][j].erase(vec[i][j].begin() + die[i][j], vec[i][j].end());
                arr[i][j] += dieAge[i][j];
            }
        }
    }
}

void seed(int y, int x){
    for(int i=y-1; i<=y+1; i++){
        for(int j=x-1; j<=x+1; j++){
            if(i<0 || i>=n || j<0 || j>=n) continue;
            if(i==y && j==x) continue;
            vec[i][j].push_back(1);
        }
    }
}

void aut(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vec[i][j].size()) continue;
            for(int t=0; t<vec[i][j].size(); t++){
                if(vec[i][j][t] != 0 && vec[i][j][t] % 5 == 0){
                    seed(i, j);
                }
            }
        }
    }
}

void winter(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] += a[i][j];
        }
    }
}

int go(){
    for(int i=0; i<k; i++){
        fill(&die[0][0], &die[0][0]+12*12, -1);
        fill(&dieAge[0][0], &dieAge[0][0]+12*12, 0);
        spring();
        summer();
        aut();
        winter();
    }
    
    int ret = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ret+=vec[i][j].size();
        }
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;
    
    fill(&arr[0][0], &arr[0][0]+12*12, 5);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        vec[x-1][y-1].push_back(z);
    }
    cout<<go();
    return 0;
}