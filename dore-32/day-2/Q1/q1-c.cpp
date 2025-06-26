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

const int MAXN = 1e6 + 25;
vector<int> g[MAXN];
int d[MAXN];

void bfs(int root) {
    queue<int> q;
    memset(d, 31, sizeof(d));
    d[root] = 0;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d[u] + 1 < d[v]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void preprocess() {

    for (int i = 1; i < MAXN; i++) {
        int u1 = i/5;
        int u2 = i+5;
        g[u1].push_back(i);
        g[u2].push_back(i);
    }

    int root = 2022;
    bfs(root);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    preprocess();

    long long n = 1e18;


    int ans = 0;

    int last_six_bit_in_base_5 = 15625 - 1;
    int first_six_bit_in_base_5 = 3125;
    const int mid = 10485;
    for (int i = first_six_bit_in_base_5; i <= last_six_bit_in_base_5; i++) {
        int max_number_of_added_digits = 20;
        for (int j = 1; j < max_number_of_added_digits; j++) {
            int dist = add(d[i], j);
            ans = add(ans, mul(dist, Pow(5, j)));
        }
        int dist = add(d[i], max_number_of_added_digits);
        if (i < mid) {
            ans = add(ans, mul(dist, Pow(5, max_number_of_added_digits)));
        } else if (i == mid) {
            ans = add(ans, mul(dist, mul(3, Pow(5, max_number_of_added_digits - 1))));
            ans = add(ans, mul(dist, mul(4, Pow(5, max_number_of_added_digits - 2))));
            ans = add(ans, dist);
        }
    }
    for (int i = 1; i <= last_six_bit_in_base_5; i++) {
        ans = add(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}