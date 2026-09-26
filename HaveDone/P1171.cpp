#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n;
int g[25][25];
int dp[20][(1<<20)];
int dfs(int x,int s){
    if(s == (1<<n)-1 ) return g[x][0];
    if(dp[x][s]!=-1) return dp[x][s];
    int ans = inf;
    for(int i = 0;i < n;i++){
        if(((s>>i)&1) == 0){
            ans = min(ans,dfs(i,s | (1<<i))+g[x][i]);
        }
    }
    return dp[x][s] = ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> g[i][j];
        }
    }
    cout<<dfs(0,1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}