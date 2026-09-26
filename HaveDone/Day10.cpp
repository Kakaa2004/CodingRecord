#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int h;
    int v;
};
void solve(){
    int n;cin >> n;
    vector<node>v(n+1);
    for(int i = 1;i <= n;i++){
        cin >> v[i].h >> v[i].v;
    }
    stack<int>st1;
    vector<int>vis(n+1);
    for(int i = n;i>0;i--){
        while(st1.size()&&v[st1.top()].h<v[i].h) st1.pop();
        if(st1.size()) vis[st1.top()] += v[i].v;
        st1.push(i);
    }
    stack<int>st2;
    for(int i = 1;i<=n;i++){
        while(st2.size()&&v[st2.top()].h<v[i].h) st2.pop();
        if(st2.size()) vis[st2.top()] += v[i].v;
        st2.push(i);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = min(ans,vis[i]);
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}