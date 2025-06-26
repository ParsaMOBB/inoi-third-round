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

bool cmp(int x, int y) {
    return lw[x] > lw[y];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n = 100;
    for (int i = 1; i <= n; i++) {
        cin >> lw[i] >> up[i];
        a[i] = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = mul(ans, n - lw[a[i]] + 1 - i + 1);
    }
    cout << ans << endl;
    return 0;
}