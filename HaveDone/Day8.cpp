#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// bool check(ll x,ll m){
//     return (x*x*x+3*x*x+2*x)<=6*m;
// }
void solve(){
    ll m;cin >> m;
    ll l = 0,r = 1.99e6;
    auto f = [&](ll x,ll y)->bool{
        return (x*x*x+3*x*x+2*x)<=6*y;
    };
    while(l+1!=r){
        ll mid = (l+r)>>1;
        if(f(mid-1,m)){
            l = mid;
        }else r = mid;
    }
    cout<<l<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}