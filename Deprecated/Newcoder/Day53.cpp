#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 505;
int n;
int a[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (isdigit(ch)) {
        s = (s << 3) + (s << 1) + ch - 48;
        ch = getchar();
    }
    return s * f;
}
int is_max(int x, int y) {
    int ans = -inf;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, a[x + dx[i]][y + dy[i]]);
    }
    return (ans < a[x][y] ? ans : inf);
}
int is_min(int x, int y) {
    int ans = inf;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, a[x + dx[i]][y + dy[i]]);
    }
    return (a[x][y] < ans ? ans : inf);
}
void solve() {
    memset(a, 0, sizeof(a));
    n = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) {
                continue;
            }
            if (a[i][j] < 0) {
                int ans = is_min(i, j);
                if (ans != inf && ans >= 0) {
                    a[i][j] = 0;
                } else {
                    printf("NO\n");
                    return;
                }
            } else {
                int ans = is_max(i, j);
                if (ans != inf && ans <= 0) {
                    a[i][j] = 0;
                } else {
                    printf("NO\n");
                    return;
                }
            }
        }
    }
    printf("YES\n");
}
int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}