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
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return s * f;
}
void print(int x) {
    int top = 0;
    int data[100];
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    while (x > 0) {
        data[top++] = x % 10;
        x /= 10;
    }
    if (!top) {
        putchar('0');
    } else {
        for (int i = top - 1; i >= 0; i--) {
            putchar(data[i] + '0');
        }
    }
}
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - (a / b) * y;
    return d;
}
void solve() {
    int n = read(), p = read();
    vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x, y;
        exgcd(i, p, x, y);
        inv[i] = (x + p) % p;
    }
    for (int i = 1; i <= n; i++) {
        print(inv[i]);
        printf("\n");
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}