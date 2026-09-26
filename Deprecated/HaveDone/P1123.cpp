#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int arr[10][10];
int dfs(int x,int y,int s1,int s2){
    if(x==n) return 0;
    if(y==m) return dfs(x+1,0,s2,0);
    int ans = dfs(x,y+1,s1,s2 & (~(1<<y)));
    if(y!=0 && (s2>>(y-1))) return ans;
    for(int i = (y==0?y:y-1);i<=y+1;i++){
        if((s1>>i)&1) return ans;
    }
    ans = min(ans,dfs(x,y+1,s1,s2 | (1<<y))+arr[x][y]);
    return ans;
}
void solve(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) cin >> arr[i][j];
    }
    cout<<dfs(0,0,0,0)<<"\n";    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}