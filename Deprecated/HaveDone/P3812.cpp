#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<ll>basis(51);
    for(int i = 0;i < n;i++){
        ll tmp = a[i];
        for(int j = 50;j >= 0;j--){
            if((tmp>>j)&1){
                if(!basis[j]){
                    basis[j] = tmp;
                    break;
                }else{
                    tmp ^= basis[j];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 50;i>=0;i--){
        if(((ans>>i)&1) == 0){
            ans ^= basis[i];
        }
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