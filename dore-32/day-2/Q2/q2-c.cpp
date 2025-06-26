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

const int N = 110;
int lw[N];
int up[N];
int a[N];
int l[N];

bool cmp(int x, int y) {
    return l[x] > l[y];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n = 100;
    for (int i = 1; i <= n; i++) {
        cin >> lw[i] >> up[i];
        a[i] = i;
    }
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (up[i] != n) {
            vec.push_back(i);
        }
    }

    int ans = 0;
    int m = vec.size();
    for (int mask = 0; mask < (1<<m); mask++) {
        for (int i = 1; i <= n; i++) {
            l[i] = lw[i];
        }
        for (int j = 0; j < m; j++) {
            if (mask & (1<<j)) {
                l[vec[j]] = up[vec[j]] + 1;
            }
        }
        sort(a + 1, a + n + 1, cmp);
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res = mul(res, n - l[a[i]] + 1 - i + 1);
        }
        if (__builtin_popcount(mask) & 1) {
            ans = add(ans, MOD - res);
        } else {
            ans = add(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}