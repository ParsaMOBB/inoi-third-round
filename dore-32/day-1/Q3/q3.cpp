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

const int N = 1e6 + 6;
int f[N];
int ind[N];
int outd[N];
int ans = 0;

void inc(int u) {
    outd[u]++;
    if (outd[u] <= ind[u]) 
        ans = add(ans, MOD-1);
}

int main() {
    int n = 1000000;
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        int cnt = 0;
        inc(1);
        cnt++;
        for (int k = 2; k * k <= i; k++) {
            inc(k);
            cnt++;
            int x = i/k;
            if (x != k) {
                inc(x);
                cnt++;
            }
        }
        ind[i] = cnt;
        ans = add(ans, cnt);
        sum = add(sum, ans);
    }
    cout << Pow(ans, 3) << '\n';
    cout << Pow(sum, 3) << '\n';
}

