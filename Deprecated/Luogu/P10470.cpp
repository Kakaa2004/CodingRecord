#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int cnt;
int tree[N][26];
int End[N];
void insert(string s){
    int len = s.size();
    int cur = 1;
    for(int i = 0;i < len;i++){
        int path = s[i]-'a';
        if(tree[cur][path] == 0){
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
    }
    End[cur]++;
}
int query(string s){
    int len = s.size();
    int cur = 1;
    int res = 0;
    for(int i = 0;i < len;i++){
        int path = s[i]-'a';
        if(tree[cur][path] == 0){
            return res;
        }
        cur = tree[cur][path];
        res += End[cur];
    }
    return res;
}
void solve(){
    cnt = 1;
    int n,m;cin >> n >> m;
    for(int i = 0;i < n;i++){
        string s;cin >> s;
        insert(s);
    }
    for(int i = 0;i < m;i++){
        string s;cin >> s;
        cout<<query(s)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}