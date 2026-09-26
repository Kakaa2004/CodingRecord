#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e6+5;
int cnt;
int tree[N][62];
int pass[N];
int get(char ch){
    if(isdigit(ch)){
        return ch-'0'+52;
    }else if(ch>='A'&&ch<='Z'){
        return ch-'A'+26;
    }else{
        return ch-'a';
    }
}
void Insert(string s){
    int len = s.size();
    int cur = 1;
    pass[cur]++;
    for(int i = 0;i < len;i++){
        int path = get(s[i]);
        if(tree[cur][path]==0){
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
}
int query(string s){
    int cur = 1;
    int len = s.size();
    for(int i = 0;i < len;i++){
        int path = get(s[i]);
        if(tree[cur][path]==0){
            return 0;
        }
        cur = tree[cur][path];
    }
    return pass[cur];
}
void solve(){
    for(int i = 1;i <= cnt;i++){
        for(int j = 0;j < 62;j++){
            tree[i][j] = 0;
        }
    }
    for(int i = 1;i <= cnt;i++){
        pass[i] = 0;
    }
    cnt = 1;
    int n,q;cin >> n >> q;
    for(int i = 1;i <= n;i++){
        string s;cin >> s;
        Insert(s);
    }
    for(int i = 1;i <= q;i++){
        string s;cin >> s;
        printf("%d\n",query(s));
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}