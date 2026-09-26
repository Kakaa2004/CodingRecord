#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int fa[N],dis[N],Size[N];
int get(int x){
    if(fa[x] == x){
        return x;
    }else{
        int fx = get(fa[x]);
        dis[x] += dis[fa[x]];
        return fa[x] = fx;
    }
}
void merge(int x,int y){
    int fx = get(x);
    int fy = get(y);
    if(fx==fy) return ;
    fa[fx] = fy;
    dis[fx] += Size[fy];
    Size[fy] += Size[fx];    
}
void solve(){
    for(int i = 0;i < N;i++){
        Size[i] = 1;
        fa[i] = i;
        dis[i] = 0;
    }
    int t;cin >> t;
    for(int i = 0;i < t;i++){
        string op;
        int a,b;
        cin >> op >> a >> b;
        if(!op.compare("M")){
            merge(a,b);
        }else{
            if(a==b){
                cout<<"0\n";
                continue;
            }
            int fa = get(a);
            int fb = get(b);
            if(fa==fb){
                cout<<abs(dis[a]-dis[b]) - 1<<"\n";
            }else{
                cout<<"-1"<<"\n";
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}