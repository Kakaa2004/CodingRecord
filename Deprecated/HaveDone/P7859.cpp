#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 25;
int g[N][N];
int n,m;
int lowbit(int x){
    return x&(-x);
}
int dfs(int x,int status){
    if(x>n) return 1;
    int ans = dfs(x+1,status);
    for(int i = 1;i<=n;i++){
        if(g[x][i] && (status>>i)&1 == 1) return ans;
    }
    return ans + dfs(x+1,status  ^ (1<<x));
}
void solve(){
    cin >> n >> m;
    for(int i = 0,u,v;i < m;i++){
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    cout<<dfs(1,0)<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}