#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p;
int g[305][305];
int reserve[305];
int match[305];
bool dfs(int x){
    for(int i = 1;i <= n;i++){
        if(!reserve[i]&&g[x][i]){
            reserve[i] = 1;
            if(!match[i]||dfs(match[i])){
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    for(int i = 0;i < 305;i++){
        for(int j = 0;j < 305;j++) g[i][j] = 0;
    }
    for(int i = 0;i < 305;i++) match[i] = 0;
    cin >> p >> n;
    for(int i = 1;i <= p;i++){
        int t;cin >> t;
        for(int j = 0;j < t;j++){
            int v;cin >> v;
            g[i][v] = 1;
        }
    }
    int sum = 0;
    for(int i = 1;i <= p;i++){
        for(int j = 0;j < 305;j++) reserve[j] = 0;
        if(dfs(i)) sum++;
    }
    if(sum==p){
        cout<<"YES\n";
    }else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}