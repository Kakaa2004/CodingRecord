#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int w,h,v;cin >> w >> h >> v;
    vector<vector<int>>g(205,vector<int>(205));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            g[i][j] = 1;
        }
    }
    for(int i = h;i < h+w;i++){
        for(int j = 0;j < w+v;j++){
            g[i][j] = 1;
        }
    }
    for(int i = 0;i < h+w;i++){
        for(int j = 0;j < v+w;j++){
            if(g[i][j]) cout<<"Q";
        }
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}