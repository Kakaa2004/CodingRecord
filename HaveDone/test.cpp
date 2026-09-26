#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){ 
    int s1 = 3,s2 = 3,s3 = 3;
    vector<int>v(200);
    int ans = 0;
    int sum = 0;
    for(int i = 1;i <=s1;i++){
        for(int j = 1;j <=s2;j++){
            for(int k = 1;k<=s3;k++){
                v[i+j+k]++;
                if(v[i+j+k]>sum){
                    sum = v[i+j+k];
                    ans = i+j+k;
                }
            }
        }
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}
// 64 位输出请用 printf("%lld")