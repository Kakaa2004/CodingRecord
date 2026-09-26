#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
void solve() {
    ll x1, x2, n, m, l;
    cin >> x1 >> x2 >> n >> m >> l;
    ll a, c, x, y;
    if (x1 < x2) {
        a = n - m;
        c = x2 - x1;
    } else {
        a = m - n;
        c = x1 - x2;
    }
    if (a < 0) {
        a = -a;
        c = l - c;
    }
    ll d = exgcd(a, l, x, y);
    if (c % d != 0) {
        cout << "Impossible\n";
    } else {
        x *= c / d;
        ll dx = l / d;
        cout << x + (x <= 0 ? (dx - x) / dx * dx : -(x - 1) / dx * dx) << "\n";
    }
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