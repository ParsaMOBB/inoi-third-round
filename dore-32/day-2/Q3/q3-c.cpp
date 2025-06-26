#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

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

int n = 1401, m = 2022;
int a[N][N];
int dp[N][N];
int c[N][N];

void input() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[j][i];
        }
    }
    swap(n, m);
}

const int ans_b = 4705122;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();

    int ans = 0;

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            ans = add(ans, dp[i][j]);
            if (i > 1 && a[i][j] == a[i-1][j]) {
                ans = add(ans, dp[i-1][j]);
            }
            if (i < n && a[i][j] == a[i+1][j]) {
                ans = add(ans, dp[i+1][j]);
            }
            dp[i][j] = add(dp[i][j], 1);
            if (a[i][j] == a[i][j+1]) {
                dp[i][j+1] = add(dp[i][j+1], dp[i][j]);
            }
            if (i > 1 && a[i][j] == a[i-1][j] && a[i][j] == a[i-1][j+1]) {
                dp[i-1][j+1] = add(dp[i-1][j+1], dp[i][j]);
            }
            if (i < n && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1]) {
                dp[i+1][j+1] = add(dp[i+1][j+1], dp[i][j]);
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (i > 1 && a[i][j] == a[i-1][j]) {
                c[i][j] = add(c[i][j], c[i-1][j]);
            }
            ans = add(ans, c[i][j]);
            if (i > 1 && a[i][j] == a[i-1][j]) {
                ans = add(ans, MOD - 1);
            }
            c[i][j] = add(c[i][j], 1);
        }
    }
    
    cout << add(mul(add(ans, add(ans_b, MOD - mul(n, m))), 2), mul(n, m)) << endl;
    return 0;
}