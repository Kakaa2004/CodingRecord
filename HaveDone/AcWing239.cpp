#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e4+5;
int fa[N],dis[N];
int cnt = 5;
struct node{
    int a;
    int b;
    int ans;
};
int get(int x){
    if(fa[x] == x){
        return x;
    }else{
        int fx = get(fa[x]);
        dis[x] = dis[x] ^ dis[fa[x]];
        return fa[x] = fx;
    }
}
void merge(int x,int y,int d){
    int fx = get(x);
    int fy = get(y);
    fa[fx] = fy;
    dis[fx] = dis[y] ^ d ^ dis[x];
}

void solve(){
    for(int i = 0;i < N;i++){
        dis[i] = 0;
        fa[i] = i;
    }
    vector<node>v;
    vector<int>t;
    int n,m;cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b,ans = 0;
        string s;
        cin >> a >> b >> s;
        t.push_back(a-1);
        t.push_back(b);
        if(s[0]=='o') ans = 1;
        v.push_back({a-1,b,ans});
    }    
    sort(t.begin(),t.end());
    unordered_map<int,int>mp;
    for(int i = 0;i < t.size();i++){
        if(mp[t[i]] == 0){
            mp[t[i]] = ++cnt;
        }
    }
    for(int i = 0;i < m;i++){
        int d = v[i].ans;
        if(get(mp[v[i].a] ) != get(mp[v[i].b])){
            merge(mp[v[i].a],mp[v[i].b],d);
        }else if( (dis[mp[v[i].a]]^dis[mp[v[i].b]]) != d){
            cout<<i<<"\n";
            return ;
        }
    }
    cout<<m<<"\n";    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}