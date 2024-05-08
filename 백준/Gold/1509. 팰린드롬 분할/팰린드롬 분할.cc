#include <bits/stdc++.h>
using namespace std;

string str;
int dp[2504][2504]; // 회문 여부를 저장하는 DP 배열
int cut[2504]; // 최소 분할 횟수를 저장하는 DP 배열

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    int n = str.length();

    // 모든 부분 문자열에 대해 회문 여부 초기화
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1; // 길이 1인 부분 문자열은 항상 회문
        if(i < n-1 && str[i] == str[i+1]) dp[i][i+1] = 1; // 길이 2인 부분 문자열 확인
    }

    // 길이가 3 이상인 부분 문자열에 대해 회문 여부 확인
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n-len; i++) {
            int j = i + len - 1;
            if(str[i] == str[j] && dp[i+1][j-1]) dp[i][j] = 1; // 양 끝 문자가 동일하고, 내부 문자열이 회문인 경우
        }
    }

    // 최소 분할 횟수 계산
    for(int i = 0; i < n; i++) {
        if(dp[0][i]) {
            cut[i] = 0; // 처음부터 i까지의 부분 문자열이 회문인 경우 분할 필요 없음
        } else {
            cut[i] = INT_MAX;
            for(int j = 0; j < i; j++) {
                if(dp[j+1][i] && cut[j] + 1 < cut[i]) {
                    cut[i] = cut[j] + 1; // j+1부터 i까지 회문이면, 최소 분할 횟수 갱신
                }
            }
        }
    }

    cout << cut[n-1] + 1; // 분할 횟수는 회문의 갯수보다 1 작으므로 1을 더해줌
    return 0;
}
