#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x2(int x){
    return 1l*x*x;
}
void solve(){
    int n,m;cin >> n >> m;
    vector<int>a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = 1e18;
    for(int i = 0;i+m-1<n;i++){
        ans = min(ans,1l*(x2(a[i+m-1])-x2(a[i])));
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}