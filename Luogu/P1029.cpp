#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    if (a % b != 0) {
        cout << 0 << "\n";
        return;
    } else {
        a /= b;
    }
    ll cnt = 0;
    for (int i = 2; i <= a; i++) {
        if (a % i == 0) {
            cnt++;
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    cout << ((ll)(1l << cnt)) << "\n";
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