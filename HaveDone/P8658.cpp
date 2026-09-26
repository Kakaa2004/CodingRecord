#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
unordered_map<string,int>mp;
int dfs(){
    if(mp.count(s)) return mp[s];
    if(s.find("LOL") != -1) return -1;
    if(s.find("*") == string::npos) return 0;
    int ans = -2;
    for(int i = 0;i < s.size();i++){
        if(s[i]=='*'){
            s[i] = 'L';
            ans = min(ans,-1*dfs());
            s[i] = '*';
            mp[s] = ans;
            if(ans == 1) return 1;
            s[i] = 'O';
            ans = min(ans,-1*dfs());
            s[i] = '*';
            mp[s] = ans;
            if(ans == 1) return 1;
        }
    }
    return ans;
}
void solve(){
    cin >> s;
    if(s.size() < 3){
        cout<< -1<<"\n";
        return ;
    }
    cout<<dfs()<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}