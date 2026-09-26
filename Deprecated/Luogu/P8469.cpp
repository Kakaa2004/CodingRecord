#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int res = 1, ans = inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = min(ans, a[i]);
    }
    for (int i = 0; i < n; i++) {
        res = ((ll)res * (a[i] / ans)) % MOD;
    }
    cout << ans << " " << res << "\n";
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