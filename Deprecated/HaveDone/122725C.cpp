#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int arr[N];
int n,m;
bool check(int mid){
    int cnt = 0;
    for(int i = 1;i < n;i++){
        if(arr[i-1]==arr[i]){
            if(mid==0) return false;
            cnt++;
        }else if(arr[i-1]>arr[i]){
            if(mid==0) return false;
            if((arr[i-1]-arr[i])%mid==0){
                cnt += (arr[i-1]-arr[i])/mid + 1;
            }else cnt += (arr[i-1]-arr[i]+mid-1)/mid;
        }
        if(cnt>m){
            return false;
        }
    }
    return true;
}
void solve(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int l = -1,r = 1e9+5;
    while(l+1!=r){
        int mid = (l+r)>>1;
        if(check(mid)){
            r = mid;
        }else l = mid;
    }
    if(r==1e9+5){
        cout<<"-1\n";
        return;
    }
    cout<<r<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    int t = 1; cin >> t;
    while(t--) solve();
    
    return 0;
}