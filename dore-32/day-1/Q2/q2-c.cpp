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

const int N = 2e6 + 1;
vector<int> g[N];
bool mark[N];
int dp[N];

void dfs(int v, int p = -1) {
    if (mark[v] == 0) dp[v] = 1;
    bool isleaf = true;
    for (int u : g[v]) if (u != p) {
        isleaf = false;

        dfs(u, v);

        if (mark[v] == 1) 
            dp[v] = add(dp[v], dp[u]);
        else 
            dp[v] = mul(dp[v], dp[u]);
    }
    if (isleaf) dp[v] = 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = 1401401;
    int k = 202022;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        int v; cin >> v;
        mark[v] = 1;
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(1);

    cout << dp[1] << '\n';
}