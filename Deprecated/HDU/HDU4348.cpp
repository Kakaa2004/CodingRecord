#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int arr[N],root[N];
int ls[N<<5],rs[N<<5];
ll lazy[N<<5];
ll sum[N<<5];
int cnt;
int n,m;
int clone(int p){
    int rt = ++cnt;
    ls[rt] = ls[p];
    rs[rt] = rs[p];
    sum[rt] = sum[p];
    lazy[rt] = lazy[p];
    return rt;
}
int build(int l,int r){
    int rt = ++cnt;
    if(l==r){
        sum[rt] = arr[l];
    }else{
        int mid = (l+r)>>1;
        ls[rt] = build(l,mid);
        rs[rt] = build(mid+1,r);
        sum[rt] = sum[ls[rt]] + sum[rs[rt]];
    }
    lazy[rt] = 0;
    return rt;
}
int add(int L,int R,int v,int l,int r,int i){
    int rt = clone(i);
    sum[rt] += 1l*v*(min(R,r)-min(L,l)+1);
    if(L<=l&&r<=R){ 
        lazy[rt] += v; 
    }else{
        int mid = (l+r)>>1;
        if(L<=mid){
            ls[rt] = add(L,R,v,l,mid,ls[rt]);
        }
        if(R>mid){
            rs[rt] = add(L,R,v,mid+1,r,rs[rt]);
        }
    }
    return rt;
}
ll query(int L,int R,int l,int r,int i,ll res){
    if(L<=l&&r<=R){
        return sum[i] + (r-l+1)*res;
    }
    ll ans = 0;
    int mid = (l+r)>>1;
    if(L<=mid){
        ans += query(L,R,l,mid,ls[i],res+lazy[i]);
    }
    if(R>mid){
        ans += query(L,R,mid+1,r,rs[i],res+lazy[i]);
    }
    return ans;
}
void solve(){
    cin >> n >> m;
    cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    int cur = 0;
    root[cur] = build(1,n);
    for(int i = 1;i <= m;i++){
        string op;cin >> op;
        if(op=="C"){
            int l,r,d;cin >> l >> r >> d;
            root[cur+1] = add(l,r,d,1,n,root[cur]);
            cur++;  
        }else if(op=="Q"){
            int l,r;cin >> l >> r;
            cout<<query(l,r,1,n,root[cur],0)<<"\n";
        }else if(op=="H"){
            int l,r,t;cin >> l >> r >> t;
            cout<<query(l,r,1,n,root[t],0)<<"\n";
        }else{
            int t;cin >> t;
            cur = t;
        }
    }
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}