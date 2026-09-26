#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int val;
    int date; 
};
int n;
bool cmp(node a,node b){
    return a.date<b.date;
}
void solve(){
    vector<node>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i].val >> a[i].date;
    }
    sort(a.begin(),a.end(),cmp);
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 0;i < n;i++){
        if(q.size()<a[i].date){
            q.push(a[i].val);
        }else if(q.size() == a[i].date && q.top()<a[i].val){
            q.pop();
            q.push(a[i].val);
        }
    }
    ll ans = 0;
    while(q.size()){
        ans += q.top();q.pop();
    }
    cout<<ans<<"\n";
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