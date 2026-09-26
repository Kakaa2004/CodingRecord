#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<ll>a(n+1);
    a[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j<=i-1;j++){
            a[i] += a[j]*a[i-j-1];
        }
    }
    cout<<a[n];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    int t = 1;
    while(t--) solve();
    return 0;
}