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

int lw[] = {1, 2, 5, 3, 6, 1, 1, 2, 1, 2, 3};
int up[] = {11, 10, 7, 9, 11, 7, 4, 8, 10, 11, 5};
int p[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n = 11;
    
    int ans = 0;
    do {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (p[i] < lw[i] || p[i] > up[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = add(ans, 1);
        }
    } while (next_permutation(p, p + n));
    cout << Pow(ans, 4) << endl;
}