#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = (s << 3) + (s << 1) + (ch - 48);
        ch = getchar();
    }
    return s * f;
}
void solve() {
    int n = read();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    if (a[0] == a[n - 1] && n != 1) {
        cout << "1\n";
        return;
    }
    for (int i = 1; i < n - 2; i++) {
        if (a[i] == a[0] && a[i + 1] == a[n - 1]) {
            cout << "2\n";
            return;
        }
    }
    cout << "-1\n";
}
int main() {
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}