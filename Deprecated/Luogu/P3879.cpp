#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;
vector<vector<int>>a(N);
void solve(){
    int n;cin >> n;
    int cnt = 0;
    unordered_map<string,int>mp;
    for(int i = 1;i <= n;i++){
        int m;cin >> m;
        for(int j = 1;j <= m;j++){
            string s;cin >> s;
            if(mp.count(s)==0){
                mp[s] = ++cnt;
            }
            a[mp[s]].push_back(i);
        }
    }
    int m;cin >> m;
    for(int i = 1;i <= m;i++){
        string s;cin >> s;
        if(mp.count(s)==0){
            cout<<"\n";
            continue;
        }
        int k = mp[s];
        int len = a[k].size();
        cout<<a[k][0]<<" ";
        for(int i = 1;i < len;i++){
            if(a[k][i]!=a[k][i-1]){
                cout<<a[k][i]<<" ";
            }
        }
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t =  1;
    while(t--) solve();
    return 0;
}