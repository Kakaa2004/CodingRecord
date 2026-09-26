#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s;cin >> s;
    ll ans = 0;
    vector<ll> dp(4);
    for(char ch:s){
        if(ch >='a' && ch<='z') dp[0]++;
        else if(ch>='0' && ch<='9') dp[1]++;
        else if(ch>='A' && ch<='Z') dp[2]++;
        else dp[3]++;
    }
    if(dp[0]>1) ans += 65 * dp[0]; 
    else ans += 25 * dp[0];
    if(dp[1] > 1) ans += 65 * dp[1];
    else ans += 9 * dp[1];
    if(dp[2] > 1) ans += 65 * dp[2];
    else ans += 25 * dp[2];
    if(dp[3] > 1) ans += 65 * dp[3];
    else ans += 3 * dp[3];
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}