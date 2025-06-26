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

int main() {
    int n = 20;
    int k = 10;
    int sum = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
        if (__builtin_popcount(mask) == k) {
            int l = __builtin_clz(mask);
            int r = __builtin_ctz(mask);
            int len = 32 - r - l;
            sum = add(sum, len);
        }
    }
    cout << Pow(sum, 2) << '\n';
}