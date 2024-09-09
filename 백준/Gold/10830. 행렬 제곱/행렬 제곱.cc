#include <bits/stdc++.h>
using namespace std;

long long N, B;
long long arr[5][5]; 
long long ret[5][5];
long long temp[5][5];

void my_print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}

void init_temp() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = ret[i][j];
        }
    }
}

long long go(int num1, int num2) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += temp[num1][i] * temp[i][num2];
    }
    return sum%1000;
}

long long go2(int num1, int num2) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += temp[num1][i] * arr[i][num2];
    }
    return sum%1000;
}

void solve(long long cnt) {
    if (cnt == 1) {
        return;
    }

    solve(cnt / 2);
    
    // temp와 ret의 곱셈 결과를 ret에 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret[i][j] = go(i, j);
        }
    }
    
    if (cnt % 2) {
        init_temp();
        // temp와 arr의 곱셈 결과를 ret에 저장
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ret[i][j] = go2(i, j);
            }
        }
    }
    
    init_temp();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input_num;
            cin >> input_num;
            arr[i][j] = input_num % 1000;
            temp[i][j] = arr[i][j];
            ret[i][j] = arr[i][j];
        }
    }

    solve(B);
    my_print();
    return 0;
}
