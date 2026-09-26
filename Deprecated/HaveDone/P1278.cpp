#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int g[25][25];
int dp[25][(1<<17)];
int dfs(int x,int s){
    if(dp[x][s]!=-1) return dp[x][s];
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(g[x][i] && ((s>>i)&1) == 0) ans = min(ans,dfs(i,s | (1<<i))+g[x][i]);
    }
    return dp[x][s] = ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    string s[n+1];
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    for(int i = 0;i <= n;i++){
        int tmp = s[i].size()-1;
        for(int j = 1;j <= n;j++){
            if(i==0){
                if(i!=j) g[i][j] = s[j].size();
                continue;
            }
            if(i!=j && s[i][tmp] == s[j][0]) g[i][j] = s[j].size();
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