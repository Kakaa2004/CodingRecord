#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
double arr[N];
double sumE[N<<2];
double sumD[N<<2];
double lazy[N<<2];
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
void up(int p){
    sumE[p] = sumE[ls(p)]+sumE[rs(p)];
    sumD[p] = sumD[ls(p)]+sumD[rs(p)];
}
void build(int p,int l,int r){
    if(l==r){
        sumE[p] = arr[l];
        sumD[p] = arr[l]*arr[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);
}
void addLazy(double v,int p,int len){
    sumD[p] += 2*v*sumE[p]+ len*v*v;
    sumE[p] += len*v;
    lazy[p] += v; 
}
void down(int p,int l,int r){
    if(lazy[p]){
        int mid = (l+r)>>1;
        addLazy(lazy[p],ls(p),mid-l+1);
        addLazy(lazy[p],rs(p),r-mid);
        lazy[p] = 0;
    }
}
void update(int L,int R,double v,int p,int l,int r){
    if(L<=l&&r<=R){
        addLazy(v,p,r-l+1);
        return ;
    }
    down(p,l,r);
    int mid = (l+r)>>1;
    if(L<=mid) update(L,R,v,ls(p),l,mid);
    if(R>mid) update(L,R,v,rs(p),mid+1,r);
    up(p);
}
double query1(int L,int R,int p,int l,int r){
    if(L<=l&&r<=R){
        return sumE[p];
    }
    down(p,l,r);
    double ans = 0;
    int mid = (l+r)>>1;
    if(L<=mid) ans+=query1(L,R,ls(p),l,mid);
    if(R>mid) ans+=query1(L,R,rs(p),mid+1,r);
    return ans;
}
double query2(int L,int R,int p,int l,int r){
    if(L<=l&&r<=R){
        return sumD[p];
    }
    down(p,l,r);
    double ans = 0;
    int mid = (l+r)>>1;
    if(L<=mid) ans+=query2(L,R,ls(p),l,mid);
    if(R>mid) ans+=query2(L,R,rs(p),mid+1,r);
    return ans;
}
void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    build(1,1,n);
    for(int i = 0;i < m;i++){
        int op;cin >> op;
        int x,y;
        double k;
        if(op==1){
            cin >> x >> y >> k;
            update(x,y,k,1,1,n);
        }else if(op==2){
            cin >> x >> y;
            printf("%.4lf\n",query1(x,y,1,1,n)/(y-x+1));
        }else{
            cin >> x >> y;
            double e = query1(x,y,1,1,n)/(y-x+1);
            double d = query2(x,y,1,1,n)/(y-x+1);
            printf("%.4lf\n",d-e*e);
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}