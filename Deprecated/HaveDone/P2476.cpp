#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int k;
int n;
int v[20];
ll dp[16][16][16][16][16][6];
int dfs(ll a,ll b,ll c,ll d,ll e,ll last){
    if(dp[a][b][c][d][e][last] != -1) return dp[a][b][c][d][e][last];
    ll ans = 0;
    if(a > 0){
        ans = (ans + (a-(last==2))*dfs(a-1,b,c,d,e,1))%MOD;
    }
    if(b > 0){
        ans = (ans + (b-(last==3))*dfs(a+1,b-1,c,d,e,2))%MOD;
    }
    if(c > 0){
        ans = (ans + (c-(last==4))*dfs(a,b+1,c-1,d,e,3))%MOD;
    }
    if(d > 0){
        ans = (ans + (d-(last==5))*dfs(a,b,c+1,d-1,e,4))%MOD;
    }
    if(e > 0){
        ans = (ans + e*dfs(a,b,c,d+1,e-1,5))%MOD;
    }
    return dp[a][b][c][d][e][last] = ans %MOD;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i <= 5;i++) dp[0][0][0][0][0][i] = 1l;
    cin >> k;
    for(int i = 1;i <= k;i++){
        cin >> n;
        v[n]++;
    }
    cout<<dfs(v[1],v[2],v[3],v[4],v[5],0)%MOD;

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}