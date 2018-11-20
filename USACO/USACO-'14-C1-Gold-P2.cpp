#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
typedef long long ll;
#define f first
#define s second

ll bit[MAXN], tree[MAXN*4], vals[MAXN];
int arr[MAXN][2];

void upd(int i, int v){
    for (;i<MAXN;i+=i&-i) bit[i] += v;
}

ll que(int i){
    ll res = 0;
    for (;i>0;i-=i&-i) res += bit[i];
    return res;
}

void build(int i, int l, int r){
    if (l==r){
        tree[i] = vals[l];
        return;
    }
    int mid = (l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i] = max(tree[i*2],tree[i*2+1]);
}

void update(int i, int l, int r, int t, int v){
    if (l==r&&l==t){
        tree[i] = v;
        return;
    }
    if (l>t||r<t) return;
    int mid = (l+r)/2;
    update(i*2,l,mid,t,v);
    update(i*2+1,mid+1,r,t,v);
    tree[i] = max(tree[i*2],tree[i*2+1]);
}

ll query(int i, int l, int r, int s, int e){
    if (l>=s&&r<=e) return tree[i];
    if (l>e||r<s) return 0;
    int mid = (l+r)/2;
    return max(query(i*2,l,mid,s,e),query(i*2+1,mid+1,r,s,e));
}

int dist(int a, int b){
    return abs(arr[a][0]-arr[b][0])+abs(arr[a][1]-arr[b][1]);
}

int main() {
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    int N,Q;
    scanf("%d %d",&N,&Q);
    int a,b,c;
    char q;
    for (int i=0;i<N;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    for (int i=1;i<N-1;i++){
        vals[i] = dist(i-1,i)+dist(i,i+1)-dist(i-1,i+1);
    }
    build(1,0,N-1);
    for (int i=0;i<N-1;i++){
        upd(i+1,dist(i,i+1));
    }
    for (int i=0;i<Q;i++){
        scanf(" %c",&q);
        if (q=='Q'){
            scanf("%d %d",&a,&b);
            a--;
            b--;
            if (a==b){
                printf("0\n");
                continue;
            }else if (b-a==1){
                printf("%d\n",dist(a,b));
                continue;
            }
            printf("%lld\n",que(b)-que(a)-query(1,0,N-1,a+1,b-1));
        }else{
            scanf("%d %d %d",&a,&b,&c);
            a--;
            arr[N][0] = b;
            arr[N][1] = c;
            if (a&&a<N-1) update(1,0,N-1,a,dist(a-1,N)+dist(a+1,N)-dist(a-1,a+1));
            if (a>1) update(1,0,N-1,a-1,dist(a-1,a-2)+dist(a-1,N)-dist(a-2,N));
            if (a<N-2) update(1,0,N-1,a+1,dist(a+1,a+2)+dist(a+1,N)-dist(a+2,N));
            if (a) upd(a,dist(N,a-1)-dist(a,a-1));
            if (a<N-1) upd(a+1,dist(N,a+1)-dist(a,a+1));
            arr[a][0] = b;
            arr[a][1] = c;
        }
    }
}
