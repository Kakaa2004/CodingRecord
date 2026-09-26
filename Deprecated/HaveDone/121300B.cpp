#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<vector<int>>arr(n+1,vector<int>(n+1,0));
    int u,v;
    for(int i = 0;i < n;i++){
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;       
    }
    for(int i = 1;i <= n;i++){
        int tot = 0;
        for(int j = 1;j <= n;j++){
            tot += arr[i][j];
            if(tot==n-1){
                cout<<i<<"\n";
                return ;
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}