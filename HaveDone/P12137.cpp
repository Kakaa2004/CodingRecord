#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int N = 1e5+5;
int dp[N];
void init(){
    dp[0] = 1;
    for(int i = 1;i < N;i++){
        dp[i] = ( dp[i-1] * 3l ) % MOD;
    }
}
void solve(){
    init();
    int n; cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll ans = 0;
    int pre = 0;
    for(int i = 1; i <= n;i++){
        pre ^= a[i];
        if(i==n) ans = (ans + pre) % MOD;
        else ans = ( ans + 2l * pre * dp[n-i-1] ) % MOD;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}