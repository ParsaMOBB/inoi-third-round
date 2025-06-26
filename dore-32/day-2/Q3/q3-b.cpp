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
// int n = 2, m = 2;
int a[N][N];
int dp[N][N][4];

void input() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

bool cmp(pii p1, pii p2) {
    return a[p1.X][p1.Y] < a[p2.X][p2.Y];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();

    vector< pii > vec;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vec.push_back({i, j});
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    int ans = 0;
    for (auto [i, j] : vec) {
        // cout << i << " " << j << endl;
        // 0 : (i, j-1) -> (i,j)
        if (j > 1 && a[i][j] > a[i][j-1]) {
            dp[i][j][0] = 1;
            int k = a[i][j] - a[i][j-1];
            // case 0 :
            if (k == a[i][j-1] - a[i][j-2]) {
                dp[i][j][0] = add(dp[i][j][0], dp[i][j-1][0]);
            }
            // case 1 :
            if (k == a[i][j-1] - a[i-1][j-1]) {
                dp[i][j][0] = add(dp[i][j][0], dp[i][j-1][1]);
            }
            // case 2 :
            if (k == a[i][j-1] - a[i][j]) {
                dp[i][j][0] = add(dp[i][j][0], dp[i][j-1][2]);
            }
            // case 3 :
            if (k == a[i][j-1] - a[i+1][j-1]) {
                dp[i][j][0] = add(dp[i][j][0], dp[i][j-1][3]);
            }
        }
        // 1 : (i-1,j) -> (i,j)
        if (i > 1 && a[i][j] > a[i-1][j]) {
            dp[i][j][1] = 1;
            int k = a[i][j] - a[i-1][j];
            // case 0 :
            if (k == a[i-1][j] - a[i-1][j-1]) {
                dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][0]);
            }
            // case 1 :
            if (k == a[i-1][j] - a[i-2][j]) {
                dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][1]);
            }
            // case 2 :
            if (k == a[i-1][j] - a[i-1][j+1]) {
                dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][2]);
            }
            // case 3 :
            if (k == a[i-1][j] - a[i][j]) {
                dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][3]);
            }
        }
        // 2 : (i, j+1) -> (i, j)
        if (j < m && a[i][j] > a[i][j+1]) {
            dp[i][j][2] = 1;
            int k = a[i][j] - a[i][j+1];
            // case 0 :
            if (k == a[i][j+1] - a[i][j]) {
                dp[i][j][2] = add(dp[i][j][2], dp[i][j+1][0]);
            }
            // case 1 :
            if (k == a[i][j+1] - a[i-1][j+1]) {
                dp[i][j][2] = add(dp[i][j][2], dp[i][j+1][1]);
            }
            // case 2 :
            if (k == a[i][j+1] - a[i][j+2]) {
                dp[i][j][2] = add(dp[i][j][2], dp[i][j+1][2]);
            }
            // case 3 :
            if (k == a[i][j+1] - a[i+1][j+1]) {
                dp[i][j][2] = add(dp[i][j][2], dp[i][j+1][3]);
            }
        }
        // 3 : (i+1, j) -> (i, j)
        if (i < n && a[i][j] > a[i+1][j]) {
            dp[i][j][3] = 1;
            int k = a[i][j] - a[i+1][j];
            // case 0 :
            if (k == a[i+1][j] - a[i+1][j-1]) {
                dp[i][j][3] = add(dp[i][j][3], dp[i+1][j][0]);
            }
            // case 1 :
            if (k == a[i+1][j] - a[i][j]) {
                dp[i][j][3] = add(dp[i][j][3], dp[i+1][j][1]);
            }
            // case 2 :
            if (k == a[i+1][j] - a[i+1][j+1]) {
                dp[i][j][3] = add(dp[i][j][3], dp[i+1][j][2]);
            }
            // case 3 :
            if (k == a[i+1][j] - a[i+2][j]) {
                dp[i][j][3] = add(dp[i][j][3], dp[i+1][j][3]);
            }
        }
        ans = add(ans, dp[i][j][0]);
        ans = add(ans, dp[i][j][1]);
        ans = add(ans, dp[i][j][2]);
        ans = add(ans, dp[i][j][3]);
    }
    ans = add(ans, mul(n, m));
    cout << ans << endl;
    return 0;
}