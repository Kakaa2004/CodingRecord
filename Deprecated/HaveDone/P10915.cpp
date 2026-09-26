#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int getNext(string s1,string s2){
    string str = s1+"#"+s2;
    int len = str.size();
    vector<int>next(len+5);
    next[0] = -1;
    next[1] = 0;
    int cnt = 0;
    int i = s1.size()+1;
    int ans = 0;
    while(i<len){
        if(str[i-1]==str[cnt]){
            next[i++] = ++cnt;
            if(i+cnt<=len+1) ans = min(ans,cnt);
        }else if(cnt>0){
            cnt = next[cnt];
        }else{
            next[i++] = 0;
        }
    }
    return ans;
}
void solve(){
    cin >> s;
    int k = 0;
    int len = s.size();
    while(s[k]==s[len-k-1]&&k<len-k-1) k++;
    s = s.substr(k,len-k*2);
    string ts = s;
    reverse(ts.begin(),ts.end());
    int ans = k+min(getNext(s,ts),getNext(ts,s));
    cout<<ans;

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}