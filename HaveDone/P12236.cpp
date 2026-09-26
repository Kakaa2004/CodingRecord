#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[20];
ll dp[16][16][(1<<16)];
ll dfs(int x,int last,int s){
    if(dp[x][last][s]!=-1) return dp[x][last][s];
    if(x == 0) return 1;
    if(a[x]){
        if(last==1) return 0;
        if((s>>(last-1)&1) == 0){
            return 0;
        }else{
            return dp[x][last][s] = dfs(x-1,last-1,s ^ (1<<(last-1)));
        }
    }else{
        ll ans = 0;
        for(int i = 1;i <= n;i++){
            if(((s>>i)&1)!=0 && i!=last-1){
                ans += dfs(x-1,i,s ^ (1<<i));
            }
        }
        return dp[x][last][s] = ans;
    }
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i = 1;i < n;i++){
        cin >> a[i];
    }
    cout<<dfs(n,0,(1<<(n+1))-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}