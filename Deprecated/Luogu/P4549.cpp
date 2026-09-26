#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        res = gcd(res, abs(tmp));
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}