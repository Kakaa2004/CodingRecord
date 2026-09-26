#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll a,b;cin >> a >> b;
    ll c = __gcd(a,b);
    int ans = 1;
    for(int i = 2;i <= c/i;i++){
        if(c%i==0){
            ans++;
            while(c%i==0){
                c/=i;
            }
        }
    }
    if(c>1) ans++;
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