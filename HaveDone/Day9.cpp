#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,a,b;cin >> n >> a >> b;
    ll odd = 0,even = 0;
    for(int i = 0;i < n;i++){
        int tmp;cin >> tmp;
        if(tmp&1) odd++;
        else even++;
    }
    if(odd>0&&even>0){
        if(b<=a){
            ll sum = 0;
            if(b<=0){
                sum += odd*even*b;
                if(a<=0){
                    sum+=a*odd*(odd-1)/2+a*even*(even-1)/2;
                }
            }else{
                sum += (n-1)*b;
            }
            cout<<sum<<"\n";
        }else{
            ll sum = 0;
            if(a>=0){
                sum = (odd+even-2)*a+b;
            }else{
                sum+= a*odd*(odd-1)/2+a*even*(even-1)/2;
                if(b<=0){
                    sum+=odd*even*b;
                }else{
                    sum+=b;
                }
            }
            cout<<sum<<"\n";
        }
    }else{
        if(a<=0){
            cout<<a*n*(n-1)/2<<"\n";
        }else{
            cout<<(n-1)*a<<"\n";
        }
        
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}