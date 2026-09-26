#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Cow{
    int min;
    int max;
};
struct Spf{
    int spf;
    int cover;
};
bool cmp(Cow a,Cow b){
    return a.min>b.min;
}
bool cmp1(Spf a,Spf b){
    return a.spf<b.spf;
}
void solve(){
    int c,l;cin >> c >> l;
    vector<Cow>a(c);
    for(int i = 0;i < c;i++){
        cin >> a[i].min >> a[i].max;
    }
    sort(a.begin(),a.end(),cmp);
    vector<Spf>s(l);
    for(int i = 0;i < l;i++){
        cin >> s[i].spf >> s[i].cover;
    }  
    sort(s.begin(),s.end(),cmp1);
    int ans = 0;
    for(int i = 0;i < c;i++){
        int k = -1;
        for(int j = 0;j < l;j++){
            if(s[j].spf>=a[i].min&&s[j].spf<=a[i].max&&
            s[j].cover>0){
                k = j;
            }
        }
        if(k!=-1){
            ans++;
            s[k].cover--;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}