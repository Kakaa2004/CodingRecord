#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    ll ans = 0;
    vector<int>v;
    for(int i = 0;i < n;i++){
        int a,b;cin >> a >> b;
        ans += a;
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i = 0;i < n;i++){
        ans -= v[i]*i;
    }
    cout<<ans<<"\n";
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;  cin >> t;
    while(t--) solve();
    
    return 0;
}