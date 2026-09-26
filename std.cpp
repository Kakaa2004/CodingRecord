#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 998244353;
const ll MOD = 1e9+7;
const int N = 1e6+5;
struct Node{
	int l,r,val,h;
	bool operator < (const Node& other)const{
		return h > other.h;
	}
};
int f[N],inv[N];
ll ksm(ll a,ll x){
    ll ans = 1;
    while(x){
        if(x&1) ans = ans*a%mod;
        a = a*a%mod;
        x >>= 1;
    }
    return ans;
}
void init(){
	f[0] = 1;
	for(int i = 1;i < N;i++){
		f[i] = 1ll * f[i-1]*i%mod;
	}
	inv[N-1] = ksm(f[N-1],mod-2);
	for(int i = N-2;i>=0;i--){
        inv[i] = 1ll * inv[i+1]*(i+1)%mod;
	}
}
ll A(ll n,ll m){
    if(n <= 0) return 0;
    if(m<=0) return 1;
    if(m>n) return 0;
    return 1ll*f[n]*inv[n-m]%mod;
}
ll C(ll n,ll m){
    if(n<m) return 0;
    if(m<0) return 0;
    if(n<0) return 0;
    return 1ll*f[n]*inv[m]%mod * inv[n-m]%mod;
}
struct SegmentTree{
	int n;
	vector<int>tree,lazy;
    map<int,int>mp;
	SegmentTree(int n){
		this->n = n;
		tree.resize((n<<2) + 5,-inf);
		lazy.resize((n<<2) + 5,-inf);
	}
	int ls(int p){
		return p<<1;
	}
	int rs(int p){
		return p<<1|1;
	}
	void pushUp(int p){
		tree[p] = min(tree[ls(p)],tree[rs(p)]);
	}
	void addLazy(int p,int k){
		tree[p] = min(tree[p],k);
		lazy[p] = min(lazy[p],k);
	}
	void pushDown(int p){
		if(lazy[p] != -inf){
			addLazy(ls(p),lazy[p]);
			addLazy(rs(p),lazy[p]);
			lazy[p] = -inf;
		}
	}
	void update(int L,int R,int k,int l,int r,int p){
		if(L<=l && r <= R){
			addLazy(p,k);
			return;
		}
		pushDown(p);
		int mid = (l+r)>>1;
		if(L<=mid) update(L,R,k,l,mid,ls(p));
		if(R>mid) update(L,R,k,mid+1,r,rs(p));
		pushUp(p);
	}
	ll query(int L,int R,int l,int r,int p){
		if(L<= l && r <= R){
			return tree[p];
		}
		pushDown(p);
		int mid = (l+r)>>1;
		ll ans = -inf;
		if(L<= mid) ans = min(ans,query(L,R,l,mid,ls(p)));
		if(R>mid) ans = min(ans,query(L,R,mid+1,r,rs(p)));
		return ans;
	}
	ll getAns(){
		dfs(1,n,1);
		ll ans = 1;
		ll cnt = 0;
		for(auto [a,b]:mp){
            if(a == -inf) continue;
            //cout<<a<<" "<<b<<"\n";
			ans = ans*C(min(n,a)-cnt-1,b-1)%mod * f[b]%mod;
			cnt += b;
		}
		ans = ans*f[n-cnt]%mod;
		return ans;
	}
	void dfs(int l,int r,int p){
		if(l == r){
			mp[tree[p]]++;
			return;
		}
		pushDown(p);
		if(tree[ls(p)] == tree[rs(p)]){
			mp[tree[p]] += r-l+1;
			return;
		}
		int mid = l+r>>1;
		dfs(l,mid,ls(p));
		dfs(mid+1,r,rs(p));
	}
};
int getDep(int x){
	int res = 0;
	while(x){
		res++;
		x>>=1;
	}
	return res-1;
}
void solve() {
	init();
	ll n,q;cin >> n >> q;
	SegmentTree seg((1<<n));
	vector<Node>arr;
	while(q--){
		int u,x;cin >> u >> x;
		int h = getDep(u);
		int l = u*(1ll<<(n-h))-(1<<n)+1,r = (u+1)*(1ll<<(n-h))-1-(1<<n)+1;
		arr.push_back({l,r,x,h});
	}
	sort(arr.begin(),arr.end());
	for(auto [l,r,val,h]:arr){
        int tmp = seg.query(l,r,1,(1<<n),1);
        cout<<l<<" "<<r<<" "<<tmp<<"\n";
		if(tmp > val){
			cout<<0<<"\n";
			return;
		}else{
		 seg.update(l,r,val,1,(1<<n),1);
		 cout<<val<<"\n";
		 }
	}
	cout<<seg.getAns()<<"\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll T; //cin >> T;while(T--)
	solve();
	return 0;
}
