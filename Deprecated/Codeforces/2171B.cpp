#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int l = 0, r = 0;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            a[i] = 0;
            if (i == 0) {
                l = 1;
            } else if (i == n - 1) {
                r = 1;
            }
        }
        if (i > 0) {
            sum += a[i] - a[i - 1];
        }
    }
    if (!l && !r) {
        cout << abs(sum) << "\n";
    } else if (l && r) {
        if (sum >= 0) {
            a[0] = sum;
            a[n - 1] = 0;
            cout << "0\n";
        } else {
            a[0] = 0;
            a[n - 1] = -1 * sum;
            cout << "0\n";
        }
    } else {
        if (l) {
            if (sum >= 0) {
                a[0] = sum;
                cout << "0\n";
            } else {
                a[0] = 0;
                cout << abs(sum) << "\n";
            }
        }
        if (r) {
            if (sum >= 0) {
                a[n - 1] = 0;
                cout << sum << "\n";
            } else {
                a[n - 1] = -1 * sum;
                cout << "0\n";
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("1.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}