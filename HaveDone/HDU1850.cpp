#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
void solve(){
    vector<int>a(m+1);
    int sum = 0;
    for(int i = 1;i <= m;i++){
        cin >> a[i];
        sum ^= a[i];
    }
    if(sum==0){
        cout<<"0\n";
        return ;
    }
    int ans = 0;
    for(int i = 1;i <= m;i++){
        int tmp = sum;
        if((tmp^a[i])<=a[i]) ans++;
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    cin >> m;
    while(m){
        solve();
        cin >> m;
    }
}