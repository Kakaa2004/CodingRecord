#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e8 + 7;
const int N = 2e5 + 5;
int fac[N];
int inv[N];
int fpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans = ((ll)ans * a) % MOD;
        }
        a = ((ll)a * a) % MOD;
        x >>= 1;
    }
    return ans;
}
void init() {
    fac[0] = inv[0] = 1;
    for (ll i = 1; i < N; i++) {
        fac[i] = ((ll)i * fac[i - 1]) % MOD;
    }
    inv[N - 1] = fpow(fac[N - 1], MOD - 2);
    for (ll i = N - 2; i >= 1; i--) {
        inv[i] = ((ll)inv[i + 1] * (i + 1)) % MOD;
    }
}
ll C(int n, int m) {
    return (((ll)fac[n] * inv[m]) % MOD) * (inv[n - m]) % MOD;
}
void solve() {
    int n;
    cin >> n;
    cout << (C(2 * n, n) - C(2 * n, n - 1) + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("1.in", "r", stdin);
    int t = 1;
    init();
    while (t--) {
        solve();
    }
    return 0;
}