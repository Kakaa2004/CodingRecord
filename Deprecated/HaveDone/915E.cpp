#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 15001000;
int ls[M],rs[M],lazy[M],sum[M];
int cnt = 1;
inline int read(){
    int s = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch=='-') f *= -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        s = 10*s+ch-'0';
        ch =getchar();
    }
    return s*f;
}
void addLazy(int p,int v,int n){
    if(v==lazy[p]) return;
    sum[p] = v*n;
    lazy[p] = v;
}
void down(int l,int r,int p){
    if(lazy[p]!=-1){
        if(!ls[p]){
            ls[p] = ++cnt;
        }
        if(!rs[p]){
            rs[p] = ++cnt;
        }
        int mid = (l+r)>>1;
        addLazy(ls[p],lazy[p],mid-l+1);
        addLazy(rs[p],lazy[p],r-mid);
        lazy[p] = -1;        
    }
}
void up(int p){
    sum[p] = sum[ls[p]] + sum[rs[p]];
}
void update(int L,int R,int v,int l,int r,int p){
    if(L<=l&&r<=R){
        addLazy(p,v,r-l+1);
        return ;
    }
    down(l,r,p);
    int mid = (l+r)>>1;
    if(L<=mid){
        if(!ls[p]){
            ls[p] = ++cnt;
        }
        update(L,R,v,l,mid,ls[p]);
    }
    if(R>mid){
        if(!rs[p]){
            rs[p] = ++cnt;
        }
        update(L,R,v,mid+1,r,rs[p]);
    }
    up(p);
}
void solve(){
    memset(lazy,-1,sizeof(lazy));
    int n = read(),q = read();
    for(int i = 1;i <= q;i++){
        int l = read(),r = read(),k = read();
        update(l,r,k&1,1,n,1);
        printf("%d\n",n-sum[1]);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}