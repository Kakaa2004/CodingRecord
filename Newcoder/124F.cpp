#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e17;
int n;
string s;
ll a[505];
ll dp[505][505];
ll dfs(int l, int r) {
    if (l >= r) {
        return 0ll;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    ll ans = inf;
    for (int i = l + 1; i <= r; i++) {
        if (s[l] == s[i] && (i - l + 1) % 2 == 0) {
            ans = min(ans, dfs(l + 1, i - 1) + dfs(i + 1, r) + (ll)a[l] * a[i]);
        }
    }
    return dp[l][r] = ans;
}
void solve() {
    memset(dp, -1, sizeof(-1));
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = dfs(0, n - 1);
    cout << (ans == inf ? -1 : ans) << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("1.in","r",stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}