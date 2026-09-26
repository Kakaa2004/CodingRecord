#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &ch : s) {
        cnt += ch == '0';
    }
    if (cnt % 2 == 0 || (s.size() - cnt) % 2 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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