#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
void solve(){
    ll n,m,k;cin >> n >> m >> k;
    auto p = [&](ll x)->bool{
        ll sum = 0;
        for(ll i = 1;i <= n;i++){
            sum += x/i;
        }
        return sum>=k;
    };
    ll l = 0,r = n*m+1;
    while(l+1!=r){
        ll mid = (l+r)>>1;
        if(p(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}