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
    x = y, y = (ll)t - (a / b) * y;
    return d;
}
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y;
    ll d = exgcd(a, b, x, y);
    if (c % d != 0) {
        cout << "-1\n";
        return;
    }
    x *= c / d;
    y *= c / d;
    ll dx = b / d;
    ll dy = a / d;
    if (x < 0) {
        ll times = (1 - x + dx - 1) / dx;
        x += times * dx;
        y -= times * dy;
    } else {
        ll times = (x - 1) / dx;
        x -= times * dx;
        y += times * dy;
    }
    if (y <= 0) {
        cout << x << " " << (y + ((1 - y + dy - 1) / dy) * dy) << "\n";
    } else {
        cout << (y - 1) / dy + 1 << " " << x << " " << (y - ((y - 1) / dy) * dy)
             << " " << (x + ((y - 1) / dy) * dx) << " " << y << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("1.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}