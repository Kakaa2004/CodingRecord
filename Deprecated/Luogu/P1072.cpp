#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
void solve() {
    int a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    int ans = 0;
    for (int i = 1; i <= b1 / i; i++) {
        if (b1 % i == 0) {
            if (i % a1 == 0)
                ans += (gcd(i / a1, a0 / a1) == 1 && gcd(b1 / b0, b1 / i) == 1);
            int j = b1 / i;
            if (i == j)
                continue;
            if (j % a1 == 0)
                ans += (gcd(j / a1, a0 / a1) == 1 && gcd(b1 / b0, b1 / j) == 1);
        }
    }
    cout << ans << "\n";
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