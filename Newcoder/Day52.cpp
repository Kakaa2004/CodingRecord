#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 205;
int g[N][N];
void solve() {
    memset(g, 0, sizeof(g));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    int line = 0, triangle = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = i + 1; k <= n; k++) {
                if (k == j) {
                    continue;
                }
                if (g[i][j] && g[j][k]) {
                    line++;
                    triangle += g[i][k];
                }
            }
        }
    }
    int d = __gcd(line, triangle);
    line /= d;
    triangle /= d;
    printf("%d/%d\n", triangle, line);
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