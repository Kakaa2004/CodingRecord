#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    ll ans =0;
    for(int i = 0;i < n-1;i++){
        ans += min(a[i+1]-a[i],0ll);
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