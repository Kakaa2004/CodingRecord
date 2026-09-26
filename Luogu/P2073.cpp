#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
struct FHQ{
    int ls,rs,key,val,siz,w;
}fhq[N];
mt19937 rnd(114514);
int root,cnt,T1,T2,T3;
void up(int x){
    fhq[x].siz = fhq[fhq[x].ls].siz + fhq[fhq[x].rs].siz + 1;
}
int init(int x,int y){
    fhq[++cnt] = {0,0,x,(int)rnd(),1,y};
    return cnt;
}
void split(int u,int v,int &x,int &y){
    if(!u){
        x = y = 0;
        return ;
    }
    if(fhq[u].key > v){
        y = u;
        split(fhq[u].ls,v,x,fhq[u].ls);
    }else{
        x = u;
        split(fhq[u].rs,v,fhq[u].rs,y);
    }
    up(u);
}
int merge(int x,int y){
    if(!x || !y){
        return x+y;
    }
    if(fhq[x].val > fhq[y].val){
        fhq[x].rs = merge(fhq[x].rs,y);
        up(x);
        return x;
    }else{
        fhq[y].ls = merge(x,fhq[y].ls);
        up(y);
        return y;
    }
}
void add(int w,int c){
    split(root,c,T1,T2);
    split(T1,c-1,T1,T3);
    if(T3){
        root = merge(merge(T1,T3),T2);
    }else{
        root = merge(merge(T1,init(c,w)),T2);
    }
}
int kth(int x){
    int u = root;
    while(u){
        int tmp = fhq[fhq[u].ls].siz + 1;
        if(tmp == x){
            break;
        }else if(tmp > x){
            u = fhq[u].ls;
        }else{
            x -= tmp;
            u = fhq[u].rs;
        }
    }
    return fhq[u].key;
}
void remove(int c){
    split(root,c,T1,T2);
    split(T1,c-1,T1,T3);
    T3 = merge(fhq[T3].ls,fhq[T3].rs);
    root = merge(merge(T1,T3),T2);
}
void dfs(int u,ll &res,ll &cst){
    if(!u){
        return ;
    }
    cst += fhq[u].key;
    res += fhq[u].w;
    dfs(fhq[u].ls,res,cst);
    dfs(fhq[u].rs,res,cst);
}
void solve(){
    int op,w,c;cin >> op;
    while(op!=-1){
        if(op == 1){
            cin >> w >> c;
            add(w,c);
        }else if(op == 2){
            remove(kth(fhq[root].siz));
        }else{
            remove(kth(1));
        }
        cin >> op;
    }
    ll res = 0,cst = 0;
    dfs(root,res,cst);
    cout<<res<<" "<<cst;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}