#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N];
int b[105];
int c[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,
           47,53,59,61,67,71,73,79,83,89,97};
void init(){
    for(int i = 1;i <= 100;i++){
        for(int j = 0;j < 25;j++){
            if(i%c[j]==0){
                int cnt = 0;
                int tmp = i;
                while(tmp%c[j]==0){
                    tmp /= c[j];
                    cnt++;
                }
                if(cnt&1){
                    b[i] ^= (1<<j);
                }
            }
        }
    }
}
void query(int l,int r){
    vector<int>v(26);
    auto p = [&](int x)->bool{
        for(int i = 24;i>=0;i--){
            if((x>>i)&1){
                if(!v[i]){
                    v[i] = x;
                    return true;
                }else{
                    x ^= v[i];
                }
            }
        }
        return false;
    };
    for(int i = l;i<= r;i++){
        if(!p(b[a[i]])){
            cout<<"Yes\n";
            return ;
        }
    }
    cout<<"No\n";
}
void solve(){
    int n,q;cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= q;i++){
        int l,r;cin >> l >> r;
        query(l,r);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    init();
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}