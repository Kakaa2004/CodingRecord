#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K;
struct node{
    int w,v;
};
void solve(){
    vector<vector<node>>arr(K+1);
    for(int i = 1;i <= n;i++){
        int a,b,c;cin >> a >> b >> c;
        arr[a].push_back({b,c});
    }
    vector<vector<int>>dp(K+1,vector<int>(m+1));
    for(int i = 1;i <= K;i++){
        for(int j = 1;j <= m;j++) dp[i][j] = -1;
    }
    for(int k = 1;k <= K;k++){
        for(int i = 0;i < arr[k].size();i++){
            for(int j = m;j>=arr[k][i].w;j--){
                if(dp[k][j-arr[k][i].w]!=-1){
                    dp[k][j] = min(dp[k][j],dp[k][j-arr[k][i].w]+arr[k][i].v);
                }
                if(dp[k-1][j-arr[k][i].w]!=-1){
                    dp[k][j] = min(dp[k][j],dp[k-1][j-arr[k][i].w]+arr[k][i].v);
                }
            }
        }
    }
    if(dp[K][m]==-1){
        cout<<"Impossible\n";
    }else cout<<dp[K][m]<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    while(cin >> n >> m >> K){
        solve();
    }
    return 0;
}