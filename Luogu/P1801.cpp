#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct node{
    int val;
    int op;
};
struct FHQ{
    int ls,rs,key,val,siz;
}fhq[N];
mt19937 rnd(114514);
int cnt,root,T1,T2,T3;
int t;
int init(int x){
    fhq[++cnt] = {0,0,x,(int)rnd(),1};
    return cnt;
}
void up(int u){
    fhq[u].siz = fhq[fhq[u].ls].siz + fhq[fhq[u].rs].siz + 1;
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
void add(int x){
    split(root,x,T1,T2);
    root = merge(merge(T1,init(x)),T2);
}
int kth(int k){
    int u = root;
    while(u){
        int tmp = fhq[fhq[u].ls].siz + 1;
        if(tmp == k){
            break;
        }
        if(tmp > k){
            u = fhq[u].ls;
        }else{
            k -= tmp;
            u = fhq[u].rs;
        }
    }
    return fhq[u].key;
}
void solve(){
    int n,m;cin >> m >> n;
    vector<node>a(m+1);
    for(int i = 1;i <= m;i++){
        cin >> a[i].val;
    }
    for(int i = 1;i <= n;i++){
        int tmp;cin >> tmp;
        a[tmp].op++;
    }
    for(int i = 1;i <= m;i++){
        add(a[i].val);
        for(int j = 1;j <= a[i].op;j++){
            cout<< kth(++t)<<"\n";
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