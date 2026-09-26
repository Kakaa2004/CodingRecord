#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5;
int ls[MAX],rs[MAX],lazy[MAX];
ll sum[MAX];
int cnt = 1;
void addLazy(int p,int v,int n){
    lazy[p] += v;
    sum[p] += 1l*n*v;
}
void down(int l,int r,int p){
    if(lazy[p]){
        if(!ls[p]){
            ls[p] = ++cnt;
        }
        if(!rs[p]){
            rs[p] = ++cnt;
        }
        int mid = (l+r)>>1;
        addLazy(ls[p],lazy[p],mid-l+1);
        addLazy(rs[p],lazy[p],r - mid);
        lazy[p] = 0;
    }
}
void up(int p){
    sum[p] = sum[ls[p]] + sum[rs[p]];
}
void add(int L,int R,int v,int l,int r,int p){
    if(L<=l && r<=R){
        addLazy(p,v,r-l+1);
        return ;
    }
    down(l,r,p);
    int mid = (l+r)>>1;
    if(L<=mid){
        if(!ls[p]){
            ls[p] = ++cnt;
        }
        add(L,R,v,l,mid,ls[p]);
    }
    if(R>mid){
        if(!rs[p]){
            rs[p] = ++cnt;
        }
        add(L,R,v,mid+1,r,rs[p]);
    }
    up(p);
}
ll query(int L,int R,int l,int r,int p){
    if(L<=l&&r<=R){
        return sum[p];
    }
    ll ans = 0;
    down(l,r,p);
    int mid = (l+r)>>1;
    if(L<=mid){
        if(ls[p]){
            ans += query(L,R,l,mid,ls[p]);
        }
    }
    if(R>mid){
        if(rs[p]){
            ans += query(L,R,mid+1,r,rs[p]);
        }
    }
    return ans;
}
void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int op;cin >> op;
        if(op==1){
            int l,r,v;cin >> l >> r >> v;
            add(l,r,v,1,n,1);
        }else{
            int l,r;cin >> l >> r;
            cout<<query(l,r,1,n,1)<<"\n";
        }
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