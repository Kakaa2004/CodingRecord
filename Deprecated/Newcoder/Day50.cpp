#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -f;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = (s << 3) + (s << 1) + ch - 48;
        ch = getchar();
    }
    return s * f;
}
void solve() {
    int n = read();
    if (n % 4 != 0) {
        printf("NO\n");
        return;
    }
    n /= 2;
    int a = 1, b = n;
    for (int i = 1; i <= n; i++) {
        printf("%d ", b);
        b += 2;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        a += 4;
    }
    printf("\n");
}
int main() {
    freopen("1.in", "r", stdin);
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}