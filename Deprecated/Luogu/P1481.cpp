#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
int tree[N][26];
int pass[N*2],End[N*2];
int cnt;
void insert(string s){
    int len = s.size();
    int cur = 1;
    for(int i = 0;i < len;i++){
        int path = s[i]-'a';
        if(tree[cur][path]==0){
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
    End[cur]++;
}
int dfs(int u){
    int res = 0;
    for(int i = 0;i < 26;i++){
        if(tree[u][i]){
            res = min(res,dfs(tree[u][i]));
        }
    }
    return res + End[u];
}
void solve(){
    cnt = 1;
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        string s;cin >> s;
        insert(s);
    }
    cout<<dfs(1)<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}