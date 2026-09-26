#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int cnt;
int tree[N][26];
void insert(string s){
    int len = s.size();
    int cur = 1;
    for(int i = 0;i < len;i++){
        int path = s[i]-'A';
        if(tree[cur][path] == 0){
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
    }
}
void solve(){
    cnt = 1;
    string s;
    while(cin >> s){
        insert(s);
    }
    cout<<cnt<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;

}