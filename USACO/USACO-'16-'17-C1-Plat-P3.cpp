#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;
#define f first
#define s second

ll tree[2][MAXN*4], lazy[MAXN*4], arr[MAXN];

void build(int i, int l, int r){
    if (l==r){
        tree[0][i] = tree[1][i] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[0][i] = tree[0][i*2]+tree[0][i*2+1];
    tree[1][i] = min(tree[1][i*2],tree[1][i*2+1]);
}

ll query(int i, int l, int r, int s, int e, int q){
    if (lazy[i]){
        tree[0][i] += lazy[i]*(r-l+1);
        tree[1][i] += lazy[i];
        if (l!=r){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (l>e||r<s){
        if (q==0) return 0;
        else return 1e18;
    }
    if (l>=s&&r<=e){
        return tree[q][i];
    }
    int mid = (l+r)/2;
    ll res;
    if (q) res = min(query(i*2,l,mid,s,e,q),query(i*2+1,mid+1,r,s,e,q));
    else res = query(i*2,l,mid,s,e,q)+query(i*2+1,mid+1,r,s,e,q);
    tree[0][i] = tree[0][i*2]+tree[0][i*2+1];
    tree[1][i] = min(tree[1][i*2],tree[1][i*2+1]);
    return res;
}

void update(int i, int l, int r, int s, int e, int v){
    if (l>=s&&r<=e){
        lazy[i] += v;
    }
    if (lazy[i]){
        tree[0][i] += lazy[i]*(r-l+1);
        tree[1][i] += lazy[i];
        if (l!=r){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (l>e||r<s) return;
    if (l>=s&&r<=e){
        return;
    }
    int mid = (l+r)/2;
    update(i*2,l,mid,s,e,v);
    update(i*2+1,mid+1,r,s,e,v);
    tree[0][i] = tree[0][i*2]+tree[0][i*2+1];
    tree[1][i] = min(tree[1][i*2],tree[1][i*2+1]);
}

int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int N,Q,a,b,c;
    scanf("%d %d",&N,&Q);
    char q;
    for (int i=0;i<N;i++){
        scanf("%lld",&arr[i]);
    }
    build(1,0,N-1);
    for (int i=0;i<Q;i++){
        scanf(" %c",&q);
        if (q=='M'){
            scanf("%d %d",&a,&b);
            a--;
            b--;
            printf("%lld\n",query(1,0,N-1,a,b,1));
        }else if (q=='P'){
            scanf("%d %d %d",&a,&b,&c);
            a--;
            b--;
            update(1,0,N-1,a,b,c);
        }else{
            scanf("%d %d",&a,&b);
            a--;
            b--;
            printf("%lld\n",query(1,0,N-1,a,b,0));
        }
    }
}

