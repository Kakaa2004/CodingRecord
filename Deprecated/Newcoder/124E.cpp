#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll fpow(ll a, ll x) {
    ll ans = 1;
    while (x) {
        if (x & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        x >>= 1;
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    cout << fpow(2l, n / 2) << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("1.in","r",stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}