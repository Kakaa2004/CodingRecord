#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto p = [&](int x) -> bool {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] / x;
            if (cnt >= k) {
                return true;
            }
        }
        return false;
    };
    int l = 0, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (p(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}