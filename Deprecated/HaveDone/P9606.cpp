#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getNext(vector<int>&next,string& s){
    int len = s.size();
    int cnt = 0;
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    while(i<=len){
        if(s[i-1]==s[cnt]){
            next[i++] = ++cnt;
        }else if(cnt>0){
            cnt = next[cnt];
        }else{
            next[i++] = 0;
        }
    }
    return next[len];
}
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string ts = s;
    reverse(ts.begin(),ts.end());
    string str = ts + "%"+ s;
    vector<int>next(str.size()+5);
    cout<<n-getNext(next,str);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}