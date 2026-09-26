#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int key[N];
int Left[N];
int Right[N];
int count[N];
int Size[N];
int diff[N];
int collect[N];
int cnt = 0;
int head = 0;
int top,father,side,ci;
double alpha = 0.7;
int createNode(int num){
    key[++cnt] = num;
    Left[cnt] = Right[cnt] = 0;
    count[cnt] = Size[cnt] = diff[cnt] = 1;
    return cnt;
}
void up(int i){
    Size[i] = Size[Left[i]] + Size[Right[i]] + count[i];
    diff[i] = diff[Left[i]] + diff[Right[i]] + (count[i] > 0?1:0);
}
void inorder(int i){
    if(i!=0){
        inorder(Left[i]);
        if(count[i] > 0){
            collect[++ci] = i;
        }
        inorder(Right[i]);
    }
}
int build(int l,int r){
    if(l>r){
        return 0;
    }
    int mid = (l+r)>>1;
    int h = collect[mid];
    Left[h] = build(l,mid-1);
    Right[h] = build(mid+1,r);
    up(h);
    return h;
}
void rebuild(){
    if(top!=0){
        ci = 0;
        inorder(top);
        if(ci > 0){
            if(father==0){
                head = build(1,ci);
            }else if(side == 1){
                Left[father] = build(1,ci);
            }else{
                Right[father] = build(1,ci);
            }
        }
    }
}
bool balance(int i){
    return diff[i]*alpha >= min(diff[Left[i]],diff[Right[i]]); 
}
void add(int u,int f,int s,int num){
    if(u==0){
        if(f == 0){
            head = createNode(num);
        }else if(s == 1){
            Left[f] = createNode(num);
        }else{
            Right[f] = createNode(num);
        }
    }else{
        if(key[u] == num){
            count[u]++;
        }else if(key[u] > num){
            add(Left[u],u,1,num);
        }else{
            add(Right[u],u,2,num);
        }
        up(u);
        if(!balance(u)){
            top = u;
            father = f;
            side = s;
        }
    }
}
void remove(int i,int f,int s,int num){
    if(key[i] == num){
        count[i]--;
    }else if(key[i] > num){
        remove(Left[i],i,1,num);
    }else{
        remove(Right[i],i,2,num);
    }
    up(i);
    if(!balance(i)){
        top = i;
        father = f;
        side = s;
    }
}
int small(int i,int num){
    if(i == 0){
        return 0;
    }
    if(key[i]>=num){
        return small(Left[i],num);
    }else{
        return Size[Left[i]] + count[i] + small(Right[i],num);
    }
}
int Rank(int num){
    return small(head,num)+1;
}
int index(int i,int x){
    if(Size[Left[i]] >= x){
        return index(Left[i],x);
    }else if(Size[Left[i]] + count[i] < x){
        return index(Right[i],x - Size[Left[i]] - count[i]);
    }
    return key[i];
}
int pre(int x){
    int kth = Rank(x);
    if(kth == 1){
        return INT_MIN;
    }
    return index(head,kth-1);
}
int post(int x){
    int kth = Rank(x+1);
    if(kth == Size[head]+1){
        return INT_MAX;
    }
    return index(head,kth);
}
void solve(){
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        int op,x;cin >> op >> x;
        switch(op){
            case 1:
                top = father = side = 0;
                add(head,0,0,x);
                rebuild();
                break;
            case 2:
                if(Rank(x)!=Rank(x+1)){
                    top = father = side = 0;
                    remove(head,0,0,x);
                    rebuild();
                }
                break;
            case 3:
                cout<<Rank(x)<<"\n";
                break;
            case 4:
                cout<<index(head,x)<<"\n";
                break;
            case 5:
                cout<<pre(x)<<"\n";
                break;
            default:
                cout<<post(x)<<"\n";
                break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}