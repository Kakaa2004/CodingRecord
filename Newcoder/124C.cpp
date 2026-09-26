#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    int l = 0, r = 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            r++;
        } else if (a[i] == a[i - 1] + 2) {
            l = r;
            r = 1;
        } else {
            l = 0;
            r = 1;
        }
        if (l + r + 1 >= m) {
            cout << "YES\n";
            return;
        }
    }
    if (r + l + 1 >= m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("1.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}