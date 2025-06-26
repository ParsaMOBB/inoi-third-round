#include <bits/stdc++.h>

using namespace std;

const int MOD = 10256483;
const int N = 2e6 + 6;
int fac[N], inv[N];


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
int C(int n, int k) {
    if (k < 0 || k > n || n < 0) {
        return 0;
    }
    return mul(fac[n], mul(inv[k], inv[n-k]));
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    inv[N - 1] = Inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = mul(inv[i + 1], i + 1);
    }
    // -----------------------------------------------------------------
    int n = 1401401;
    int k = 424242;
    int ans = 0;
    for (int l = k; l <= n; l++) {
        ans = add(ans, mul(l, mul(n-l+1, C(l-2, k-2))));
    }
    cout << ans << '\n';
}