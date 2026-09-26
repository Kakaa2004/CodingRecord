#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void change(string& s){
    bool flag = true;
    for(int i = 0;i < s.size();i++){
        if(s[i]!='0'){
            flag = false;
            s = s.substr(i,s.size());
            return ;
        }
    }
    if(flag) s = "0";
}
void solve(){
    unordered_map<string,int>mp;
    string s;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> s;
        change(s);
        cout<<s<<"\n";
        mp[s]++;
        ans = min(ans,mp[s]);
    }
    //cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    while(cin >> n){
        solve();
    } 
    return 0;
}