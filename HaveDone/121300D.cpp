#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;cin >>n ;
    vector<int>a(n+1);
    for(int i = 1,u,v;i < n;i++){
        cin >> u >> v;
        a[u]++;
        a[v]++;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(a[i]>2) ans += a[i] - 2;
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