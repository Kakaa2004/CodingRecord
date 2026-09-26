#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int>next(n+5);
    next[0] = -1;
    next[1] = 0;
    int cnt = 0;
    int k = 2;
    while(k<=n){
        if(s[k-1]==s[cnt]){
            next[k++] = ++cnt; 
        }else if(cnt>0){
            cnt = next[cnt];
        }else{
            next[k++] = 0;
        }
    }
    cout<<n-next[n]<<"\n";
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}