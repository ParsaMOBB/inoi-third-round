#include <bits/stdc++.h>

using namespace std;

const int MOD = 10256483;

int add(int a, int b) {
    return (0ll + a + b) % MOD;
}
int mul(int a, int b) {
    return 1ll * a * b % MOD;
}
int Pow(int a, int b) {
    int res = 1;
    for (; b; b>>=1, a = mul(a, a)) if (b&1) {
        res = mul(res, a);
    }
    return res;
}
int Inv(int a) {
    return Pow(a, MOD - 2);
}

const int N = 2e3 + 100;

int n = 1401;
int m = 2022;
int a[N][N];
int dp[N][N][2];

void input() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 0 : (i,j-1) -> (i,j)
            if (j > 1) {
                dp[i][j][0] = 1;
                if (a[i][j] - a[i][j-1] == a[i][j-1] - a[i][j-2]) {
                    dp[i][j][0] = add(dp[i][j][0], dp[i][j-1][0]);
                }
                if (a[i][j] - a[i][j-1] == a[i][j-1] - a[i-1][j-1]) {
                    dp[i][j][0] = add(dp[i][j][0], dp[i][j-1][1]);
                }
            }
            // 1 : (i-1,j) -> (i,j)
            if (i > 1) {
                dp[i][j][1] = 1;
                if (a[i][j] - a[i-1][j] == a[i-1][j] - a[i-2][j]) {
                    dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][1]);
                }
                if (a[i][j] - a[i-1][j] == a[i-1][j] - a[i-1][j-1]) {
                    dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][0]);
                }
            }
            ans = add(ans, dp[i][j][0]);
            ans = add(ans, dp[i][j][1]);
        }
    }
    ans = add(ans, mul(n, m));
    cout << ans << endl;
    return 0;
}