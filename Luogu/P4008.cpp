#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6+5;
struct FHQ{
    char key;
    int ls,rs,val,siz;
}fhq[N];
int root,cnt,T1,T2,T3;
mt19937 rnd(114514);
int init(char ch){
    fhq[++cnt] = {ch,0,0,(int)rnd(),1};
    return cnt;
}
void up(int x){
    fhq[x].siz = fhq[fhq[x].ls].siz + fhq[fhq[x].rs].siz + 1;
}
void split(int u,int rnk,int &x,int &y){
    if(!u){
        x = y = 0;
        return;
    }
    if(fhq[fhq[u].ls].siz >= rnk){
        y = u;
        split(fhq[u].ls,rnk,x,fhq[u].ls);
    }else{
        x = u;
        split(fhq[u].rs,rnk - fhq[fhq[u].ls].siz - 1,fhq[u].rs,y);
    }
    up(u);
}
int merge(int x,int y){
    if(!x || !y){
        return x+y;
    }
    if(fhq[x].val >= fhq[y].val){
        fhq[x].rs = merge(fhq[x].rs,y);
        up(x);
        return x;
    }else{
        fhq[y].ls = merge(x,fhq[y].ls);
        up(y);
        return y;
    }
}
void inorder(int u){
    if(u == 0){
        return ;
    }
    inorder(fhq[u].ls);
    cout<<fhq[u].key;
    inorder(fhq[u].rs);
}

void solve(){
    int q;cin >> q;
    int pos = 0;
    for(int i = 1,x;i <= q;i++){
        char op[10];cin >> op;
        if(op[0]=='I'){
            cin >> x;
            split(root,pos,T1,T2);
            for(int j = 1;j <= x;j++){
                char ch = getchar();
                while(ch<32 || ch>126){
                    ch = getchar();
                }
                T1 = merge(T1,init(ch));
            }
            root = merge(T1,T2);
        }else if(op[0] == 'D'){
            cin >> x;
            split(root,pos + x,T1,T2);
            split(T1,pos,T1,T3);
            root = merge(T1,T2);
        }else if(op[0] == 'G'){
            cin >> x;
            split(root,pos + x,T1,T2);
            split(T1,pos,T1,T3);
            inorder(T3);
            cout<<"\n";
            root = merge(merge(T1,T3),T2);
        }else if(op[0] == 'M'){
            cin >> pos;
        }else if(op[0] == 'P'){
            pos--;
        }else{
            pos++;
        }
    }
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0);
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}