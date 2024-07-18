#include <bits/stdc++.h>
using namespace std;

int N, row, col;

void go(int num , bool row_flag, bool col_flag, int y, int x, int s){
    int y_axis = 0;
    int x_axis = 0;
    if(num > 1){
        // if(row_flag) y_axis = y + pow(2, num)/2;
        // else y_axis = y;

        // if(col_flag) x_axis = x + pow(2, num)/2;
        // else x_axis = x;

        y_axis = y + pow(2, num)/2;
        x_axis = x + pow(2, num)/2;
        if(row <= y_axis){
            row_flag = false;
            y_axis = y;
        }
        else{
            row_flag = true;
        } 

        if(col <=x_axis){
            col_flag = false;
            x_axis = x;
        }else {
            col_flag = true;
        }
        int cnt = pow(pow(2, num-1), 2);
        if(row_flag && col_flag) cnt = cnt*3;
        else if (row_flag && !col_flag) cnt = cnt*2;
        else if (!row_flag && col_flag) cnt = cnt*1;
        else cnt = 0;
        // cout<<cnt<<"\n";
        go(num-1, row_flag, col_flag, y_axis, x_axis, s+cnt);
    }else{
        y_axis = y + pow(2, num)/2;
        x_axis = x + pow(2, num)/2;
        
        // if(row_flag) y_axis = y + 1;
        // else y_axis = y-1;
        // if(col_flag) x_axis =x +1;
        // else x_axis = x-1;

        if(row == y_axis){
            if(col == x_axis) cout<<s;
            else cout<<s+1;
        }else{
            if(col == x_axis) cout<<s+2;
            else cout<<s+3;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>row>>col;
    row++;
    col++;
    go(N, true, true, 0, 0, 0);
    return 0;
}