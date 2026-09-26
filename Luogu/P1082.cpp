#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
void solve() {
    int a, b;
    cin >> a >> b;
    int x, y;
    exgcd(a, b, x, y);
    cout << (x + b) % b << "\n";
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