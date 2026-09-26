#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        vector<int> a(26);
        int cnt = 0;
        for (int j = i; j < n; j += k) {
            cnt = min(cnt, ++a[s[j] - 'a']);
        }
        ans += n / k - cnt;
    }
    cout << ans;
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